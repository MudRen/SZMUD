// Code of ShenZhou
// road: /zhongnan/shanlu11.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ�����
�Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���
ʱ���˺�����������Ҫ��Хһ������������һ��ɽ·�������Ͼ�������ɽ
���塣
LONG);

        set("exits",([ "eastup" : __DIR__"shanfeng",
                        "northdown" : __DIR__"shanlu10",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
