// Code of ShenZhou
// /d/emei/jieyin.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�������ұ߱��£��ǽ���졣������һ���ʯ����״���ӣ���������ʯ����
������һʯ������ʮ���ɣ��С�����ʯ�����ɴ��������ʼ��������֣����¾�
����ʮ���̡���ϴ��ء�
LONG
	);
	set("exits", ([
		"westup" : __DIR__"wanxing",
		"northwest" : __DIR__"pan82",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}
