// Code of ShenZhou
// room: /mingjiao/shulin1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï��
��Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�
Х��ʹ�˲�����ԥ��ǰ���ĽŲ��������и�����(paizi)��
LONG );

        set("item_desc", ([
                "paizi"  : "����Ī�롣\n",
        ]));
        set("exits", ([
                "west" : __DIR__"shulin2",
                "east" : __DIR__"shanlu3",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
