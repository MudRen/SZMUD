// Code of ShenZhou
// hz_xilang2.c ����������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "����������");
	set("long", @LONG
�����Ƕ��һ��������ȡ�������������������ͨ���㳡��
LONG
	);
	set("exits", ([
		"north" : __DIR__"hz_xilang1",
		"south" : __DIR__"hz_chanfang",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}


