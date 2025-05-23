pipeline {
    agent any

    environment {
        DOCKERHUB_CREDENTIALS = credentials('dockerhub-creds') // Настроить в Jenkins Credentials
        GITHUB_TOKEN = credentials('github-token') // Настроить в Jenkins Credentials
        KUBECONFIG = credentials('kubeconfig') // Настроить для доступа к Kubernetes
    }

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Docker Login') {
            steps {
                sh 'echo $DOCKERHUB_CREDENTIALS_PSW | docker login -u $DOCKERHUB_CREDENTIALS_USR --password-stdin'
            }
        }

        stage('Build App Image') {
            steps {
                sh 'docker build -f Dockerfile.app -t git-task-app:latest .'
            }
        }

        stage('Run Tests') {
            steps {
                sh 'docker run --rm git-task-app:latest'
            }
        }

        stage('Push Images') {
            steps {
                sh '''
                docker tag git-task-app:latest ${DOCKERHUB_CREDENTIALS_USR}/git-task-app:latest
                docker push ${DOCKERHUB_CREDENTIALS_USR}/git-task-app:latest
                
                docker build -f Dockerfile.web -t ${DOCKERHUB_CREDENTIALS_USR}/git-task-web:latest .
                docker push ${DOCKERHUB_CREDENTIALS_USR}/git-task-web:latest
                '''
            }
        }

        stage('Helm Package') {
            steps {
                sh '''
                helm version
                helm package helm/test-repo-chart
                '''
            }
        }

        stage('Create Tag') {
            steps {
                sh '''
                TAG="v$(date +'%Y%m%d%H%M%S')"
                git config user.name "jenkins"
                git config user.email "jenkins@example.com"
                git tag $TAG
                git push origin $TAG
                '''
                withCredentials([string(credentialsId: 'github-token', variable: 'GITHUB_TOKEN')]) {
                    sh 'git push https://${GITHUB_TOKEN}@github.com/your-repo.git $TAG'
                }
            }
        }

        stage('Deploy to Kubernetes') {
            steps {
                sh '''
                helm upgrade --install my-release helm/test-repo-chart \
                    --set app.image.repository=${DOCKERHUB_CREDENTIALS_USR}/git-task-app \
                    --set web.image.repository=${DOCKERHUB_CREDENTIALS_USR}/git-task-web \
                    --kubeconfig $KUBECONFIG
                '''
            }
        }
    }

    post {
        always {
            sh 'docker logout'
        }
    }
}