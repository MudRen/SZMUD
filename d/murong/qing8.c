// Code of ShenZhou
// Room: /d/murong/qing8
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "Ů���");
	set("long", @LONG
    ��������ǰ�����Ů���ķ��䡣���е������ϻ���һ��
Ϊ��õ���ʽ���ۣ�����������׼��ΪĽ�ݹ������ġ�
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "east" : __DIR__"qing6",
                      ]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
