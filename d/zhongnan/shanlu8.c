// Code of ShenZhou
// road: /zhongnan/shanlu8.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ�����
�Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���
ʱ���˺�����������Ҫ��Хһ���������º����ϸ���һ��ɽ·��
LONG);

        set("exits",([ "westup" : __DIR__"shanlu9",
                        "southdown" : __DIR__"shanlu7",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

      setup();

      replace_program(ROOM);
}
