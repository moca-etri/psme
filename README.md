# 인텔 RSD v2.5 기반으로 한 렉 소프트웨어 

## TEST 환경에 따른 설정 변경 요인
 1. DHCP Discovery를 위한 DHCP Server 설정 파일에 대한 수정
   - Test 환경에 맞는 DHCP IP 대역대 수정

 2. DHCP Discovery를 위한 각 서버의 hostname 변경
    
 3. k8s 설정과 관련한 세팅을 위한 xml 파일 설정

## 변경 중인 사항
 1. RSME Agent 
  - Test 기반 서버가 IPMB를 지원하지 않는 관계로 IPMB 기반으로 BMC의 정보를 가져오는 부분를
    IPMI Remote 기반으로 BMC 정보를 가져오게 함. (수정 완료)

  - BMC의 정보 누락 분에 대한 원인 분석 및 수정 작업중
   * Node Manager에 대한 정보 누락
   * BMC의 Firmware 버전상의 문제인지 확인 중 (Redfish 지원이 되어야 함)
  

 2. PODM서버와 PSME 서버간의 인증 문제
  - https로 통신 되는 상황에서 인증 문제 발생 [세팅 문제]
   * K8s의 버전 문제로 인한 인증서가 Container내에 생성 되지 않는 문제 (K8s 자체 버그로 사료; 버전 변경으로 해결)   

