// Code of ShenZhou
// bailong.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
��������˵�ǡ����ߴ����еİ�������������֮���������ľ���죬����
�е���������ͦ���Σ�֦Ҷ����������������ӵ�𣬴�Ϊ��ʱһ��ɮ��������
��������һ�֣�ֲ��һ�꣬��ֲ�����ǧ�߰���ʮ���꣬ʱ�ƹŵ��֡����ﱱ
���������֣�������������
LONG
	);
	set("exits", ([
		"northup" : __DIR__"wannian",
		"southeast" : __DIR__"qingyin",
		"east"    : __DIR__"meihua"+(3*random(2)+1),
		"west"    : __DIR__"meihua"+(3*random(2)+1),
	]));

        set("no_clean_up", 0);
       set("fjing", 1);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
	replace_program(ROOM);

}
