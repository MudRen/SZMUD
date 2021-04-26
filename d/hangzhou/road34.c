// Code of ShenZhou
// Room: /d/hangzhou/road34.c
// modified by aln  2 / 98

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����ϼ�������������������Ϸ�������ο͡����߹���СϪ��
���������ˡ��ϱ����Ϸ������·��
LONG
	);
	set("cost", 1);
	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 4 */
        	"east" : __DIR__"road33",
                "south" : __DIR__"feilai0",
                "westup" : __DIR__"lingyin0",
        ]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
