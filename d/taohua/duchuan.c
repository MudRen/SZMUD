// Code of ShenZhou
// Room: /d/taohua/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
һ�Һ������������ʮ�ߡ��˸��ˡ�������˶��ˮ��
���ڴ�ͷ��βæ��æȥ��
LONG
	);

	set("invalid_startroom", 1);
	set("outdoors", "taohua");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



