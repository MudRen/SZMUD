// Code of ShenZhou
// d/emei/tombpath2.c С��
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "С��");
	set("long", @LONG
����һ�����ѵ�ɽ��С������ľ�������˼�������ֻ��Щ��֪����С��
��֨֨ߴߴ���š��ϱ�ͨ����üɽ��ɽ�����߾��Ǿ�ʮ�ŵ��ա�����ɽʯ��
ᾣ��������ţ����ؿ����Ѿ���������·��
LONG
	);

        set("exits", ([
		"northdown" : __DIR__"dao99",
		"southup" : __DIR__"tombpath",
        ]));

	set("cost", 6);
	setup();
        replace_program(ROOM);
}

