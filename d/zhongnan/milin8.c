// Code of ShenZhou
// road: /zhongnan/milin8.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ��ֻ��һ��ʯ��(shibei)
���ڵ��ۨ洦��������һ����Ĺ������������ï�ܵ����֡������ǻ�ɳ�롣
LONG);

        set("item_desc",(["shibei" : "

			���Ϲ�Ĺ��
			����ֹ����

\n",]));


        set("exits",([ "west" : __DIR__"huangshaling",
                        "east" : __DIR__"gumu",
				"south" : __DIR__"milin9",
				"north" : __DIR__"milin7",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
