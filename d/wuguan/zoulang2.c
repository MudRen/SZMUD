//Modified by Zyu Snso on k1-8-4
// Room: zoulang2.c ���ȣ�
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
�����������������ͺ��������ȡ�ƽʱ������Ϣ��ֻ��һ��������
ż���Ҵ��߹���
LONG
    );

    set("exits", ([
/*	"north" : __DIR__"zhuangbei",
	"south" : __DIR__"yiliaoshi",*/
	"east" : __DIR__"zhengting",
	"west" : __DIR__"houting",
    ]));

	set("no_fight", 1);
    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
}
