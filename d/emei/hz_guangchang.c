// Code of ShenZhou
// hz_guangchang.c �����ֹ㳡
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "�����ֹ㳡");
	set("long", @LONG
�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��̨�ף�ͨ����
�۱����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ�
�㳡���м���Сʦ̫�����������Դ����Ҹ���һ������ͨ���
LONG
	);
	set("exits", ([
		"southup" : __DIR__"daxiong",
		"east" : __DIR__"hz_donglang1",
		"west" : __DIR__"hz_xilang1",
		"north" : __DIR__"hz_front",
	]));

        set("objects",([
                CLASS_D("emei") + "/jingxu" : 1,
        ]));

        set("outdoors", "emei" );

        set("valid_startroom", 1);

	set("cost", 1);
	setup();
	replace_program(ROOM);
        "/clone/board/emei2_b"->foo();

}

