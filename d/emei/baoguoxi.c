// Code of ShenZhou

inherit ROOM;

void create()
{
        set("short", "��������ǽ");
	set("long", @LONG
�����Ƕ�üɽ�����µ���ǽ����Ժ���������ǽ�Ǳ�Ʈ�����ڿ����л�
�졣һ��ɽϪ������ɽ�ϵĽ����������������ɽ����ȥ��
LONG
	);
	set("exits", ([
		"east" : __DIR__"baoguo",
	]));


        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

