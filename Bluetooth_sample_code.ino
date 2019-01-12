#define MOTOR_A_SPD 10  //모터A의 속력을 결정하는 핀
#define MOTOR_B_SPD 11  //모터B의 속력을 결정하는 핀
#define MOTOR_A_DIR 12  //모터A의 방향을 결정하는 핀
#define MOTOR_B_DIR 13  //모터B의 방향을 결정하는 핀
#define A_BAL 1   //모터A 속력 균형 계수 기본값 1
#define B_BAL 1   //모터B 속력 균형 계수 기본값 1
#define M_SPEED 150   //모터 속력

unsigned char m_a_spd = 0, m_b_spd = 0; //모터의 속력을 결정하는 전역변수
boolean m_a_dir = 0, m_b_dir = 0; //모터의 방향을 결정하는 전역변수

void setup()  
{
  Serial.begin(9600); //시리얼 통신 초기화

  pinMode(MOTOR_A_DIR, OUTPUT); //모터A 방향 핀 출력으로 설정
  pinMode(MOTOR_B_DIR, OUTPUT); //모터B 방향 핀 출력으로 설정
  
  Serial.println("Hello!"); //터미널 작동 확인용 문자열
}

void loop()
{
  unsigned char bt_cmd = 0; //명령어 저장용 문자형 변수

  if (Serial.available()) //데이터가 입력되었을 때
  {
    bt_cmd = Serial.read(); //변수에 입력된 데이터 저장
    rc_ctrl_val(bt_cmd);  //입력된 데이터에 따라 모터에 입력될 변수를 조정하는 함수
  }
  motor_drive();  //모터를 구동하는 함수
}

void rc_ctrl_val(unsigned char cmd) //입력된 데이터에 따라 모터에 입력될 변수를 조정하는 함수
{
  if(cmd == 'w')  //'w'가 입력되었을 때, 전진
  {
    m_a_dir = 1;  //모터A 정방향
    m_b_dir = 0;  //모터B 정방향
    m_a_spd = M_SPEED*A_BAL;  //모터A의 M_SPEED의 PWM
    m_b_spd = M_SPEED*B_BAL;  //모터B의 M_SPEED의 PWM
  }
  else if(cmd == 'a')  //'a'가 입력되었을 때, 제자리 좌회전
  {
  
  
  
  
  }
  else if(cmd == 'd')  //'d'가 입력되었을 때, 제자리 우회전
  {
  
  
  
  
  }
  else if(cmd == 's')  //'s'가 입력되었을 때, 후진
  {
  
  
  
  
  }
  else if(cmd == 'x')
  {
    m_a_dir = 1;  //모터A 정방향
    m_b_dir = 0;  //모터B 정방향
    m_a_spd = 0;  //모터A의 정지
    m_b_spd = 0;  //모터B의 정지
  }
}

void motor_drive()  //모터를 구동하는 함수
{
  digitalWrite(MOTOR_A_DIR, m_a_dir);  //모터A의 방향을 디지털 출력
  digitalWrite(MOTOR_B_DIR, m_b_dir);  //모터B의 방향을 디지털 출력
  analogWrite(MOTOR_A_SPD, m_a_spd);  //모터A의 속력을 PWM 출력
  analogWrite(MOTOR_B_SPD, m_b_spd);  //모터B의 속력을 PWM 출력
}
