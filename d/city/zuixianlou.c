// Code of ShenZhou
// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��Բ����������������¥����˵�����˲�֪�����˲�����������ѧʿ���ε�
�ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵļѻ�����
������¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ���
�ƾ͸�·ȥ�ˡ�¥����������
LONG
	);

	set("exits", ([
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"zuixianlou2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if( present("xiao er", me) && dir="west" )
                return notify_fail("�ö˶˵��������С��������ȥ����\n");

        return ::valid_leave(me, dir);
}


