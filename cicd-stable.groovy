node('linux')
{
        stage ('Poll') {
              checkout([
                      $class: 'GitSCM',
                      branches: [[name: '*/main']],
                      doGenerateSubmoduleConfigurations: false,
                      extensions: [],
                      userRemoteConfigs: [[url: 'https://github.com/zopencommunity/bashport.git']]])
        }

        stage('Build') {
          build job: 'Port-Pipeline', parameters: [string(name: 'PORT_GITHUB_REPO', value: 'https://github.com/zopencommunity/bashport.git'), string(name: 'PORT_DESCRIPTION', value: 'Bash is the GNU Projects the Bourne Again SHell' ),  string(name: 'BUILD_LINE', value: 'STABLE') ]
        }
}
