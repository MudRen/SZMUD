//ROOM: chufang.c
inherit ROOM;

void create()
{
  set("short","ź���");
  set("long",@LONG
���Ǽ������ Ũ���ķ�����ζһ�����������ı��ӣ� ��·�����
�����������������������ܲ�֪��Դ�� ԭ������Ķ������֡�������
�񷿡�
LONG
     );
  set("exits",([
      "east" : __DIR__"changl6",
	  "west" : __DIR__"chaifang",
     ]));
  set("objects",([
    "/kungfu/class/lingjiu/tbcheng" : 1,
    __DIR__"obj/suanmei" : 2,
    __DIR__"obj/gao" : 2,  
  ]));
 setup();
 replace_program(ROOM);
}