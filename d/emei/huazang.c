// Code of ShenZhou
// huazang.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�������ǽ𶥵���Ҫ��������ģ������������������������
���������ֺ���Ƕù�̨���Ա��������֡�
LONG
	);
	set("exits", ([
		"south" : __DIR__"duguang1",
		"enter" : __DIR__"hz_front",
		"north" : __DIR__"jinding",
		"northwest" : __DIR__"woyun",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
