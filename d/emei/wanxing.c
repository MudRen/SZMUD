// Code of ShenZhou
// wanxing.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
̫��ƺ�������ǹ�����ʦ�����ġ�������ɽ����ɯ须��������źϳ�һ�䣬
Ҷ�Ӱ��ڻ��⣬��������������׶�ʢ��֮�����������Ժ�֮�߹�Ʒ�ʡ��ɴ�
�����ϱ����𶥣����������
LONG
	);
	set("exits", ([
		"southup" : __DIR__"jinding",
		"eastdown" : __DIR__"jieyin",
	]));

        set("objects", ([
                "/kungfu/class/emei/jingjia.c" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );
       set("fjing", 1);

	set("cost", 1);
	setup();
}
