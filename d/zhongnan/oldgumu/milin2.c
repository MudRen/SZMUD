// Code of ShenZhou
// road: /zhongnan/milin2.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ��ֻ��һ��ʯ��(shibei)
���ڵ��ۨ洦��������һ��յء�����������ï�ܵ����֡�
LONG);

        set("item_desc",(["shibei" : "

			���Ϲ�Ĺ��
			����ֹ����

\n",]));


        set("exits",([ "north" : __DIR__"kongdi",
                        "southwest" : __DIR__"milin4",
				"west" : __DIR__"milin3",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
