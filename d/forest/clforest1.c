// Code of ShenZhou
// /d/forest/clforest1.c
// by aln 2 / 98

inherit ROOM;

void create()
{
        int i;
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG
        );

        set("exits", ([
                "southwest" :  "/d/taihu/field",
		"east" : __DIR__"clforest2",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

