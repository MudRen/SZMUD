// Code of ShenZhou
//Jay 9/30/96

inherit ROOM;

void create()
{
        set("short", "С����");
	set("long", @LONG
���Ƕ���ɽ�𶥻��������һƬС���֡�����û��·����������ϡ��Щ��
�����ƺ��������߹���
LONG);
	set("exits", ([
		"south" : __DIR__"hztrip3",
		"north" : __DIR__"hztrip1",
	]));

        set("outdoors", "emei" );

	set("cost", 2);
	setup();
        replace_program(ROOM);

}

