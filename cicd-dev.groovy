node('linux')
{
      stage ('Poll') {
            // Poll from upstream:
            checkout([
                    $class: 'GitSCM',
                    branches: [[name: '*/devel']],
                    doGenerateSubmoduleConfigurations: false,
                    extensions: [],
                    userRemoteConfigs: [[url: "https://github.com/bminor/bash.git"]]])
            // Poll from local
            checkout([
                    $class: 'GitSCM',
                    branches: [[name: '*/main']],
                    doGenerateSubmoduleConfigurations: false,
                    extensions: [],
                    userRemoteConfigs: [[url: 'https://github.com/ZOSOpenTools/bashport.git']]])
      }

      stage('Build') {
          build job: 'Port-Pipeline', parameters: [string(name: 'PORT_GITHUB_REPO', value: 'https://github.com/ZOSOpenTools/bashport.git'), string(name: 'PORT_DESCRIPTION', value: 'Bash is the GNU Projects the Bourne Again SHell' ), string(name: 'BUILD_LINE', value: 'DEV'),  string(name: 'NODE_LABEL', value: "v2r4")]
      }
}
