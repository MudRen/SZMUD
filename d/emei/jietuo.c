// Code of ShenZhou
// jietuo.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š��������ˣ���������
Ȫ�������������������������޽�٣��ļ����ѡ�����һ�����ã�����һƬ��
�֡�����ɽϪ�����ʵ������µ����档
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"fuhuroad2",
		"west" : __DIR__"guanyin",
	]));


        set("no_clean_up", 0);
        set("outdoors", "emei" );
        set("fjing", 1);

	set("cost", 3);
	setup();
	replace_program(ROOM);
}

/*

ż��ɽ��Ѱʤ�����������Ϸ���˼��
���Ľ�������⣬���ǳ�Եδ��ʱ��

*/
