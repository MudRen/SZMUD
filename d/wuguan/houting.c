//Modified by Zyu Snso on k1-8-4
// Room: zoulang2.c ���ȣ�
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
����һ���˵����˵���ݺ������ϱ��������ȣ�Ҳ��֪������·��
�ᵽ��ʲô�ط������治ʱ�����������������Ҳ�ǳ����������ˡ���
�߾����ĵģ������������ط��ֺ��ķ�Χ������Ҳ����Ϣ���ˡ�
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang3",
	"south" : __DIR__"zoulang4",
	"east" : __DIR__"zoulang2",
	"west" : __DIR__"bedroom",
    ]));

    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
}
