// Code of ShenZhou
// road: /zhongnan/shanlu7.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ�����
�Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���
ʱ���˺�����������Ҫ��Хһ���������ºͱ��ϸ���һ��ɽ·����������
����̶��
LONG);

	  set("outdoors", "zhongnan");
      set("exits",([ "northup" : __DIR__"shanlu8",
                     "eastdown" : __DIR__"shanlu6",
                     "southdown" : __DIR__"baimatan",
	 ]));
	  set("cost",2);

      setup();

      replace_program(ROOM);
}

