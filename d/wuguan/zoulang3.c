//Creatied by Zyu Snso on k1-8-4
// Room: zoulang3.c ����3

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
��·�߹�����������Խ��ԽŨ������������ɢ�����������鲻�Խ���
�ñ���ʹ���������ᣬ�����������������ˣ�����ķ��ﴫ����ľײ����
���������Ǹ�λǰ������˵����������������һ��Ư���ķ��ӣ������˳�
�������ģ���Ҳ������������ȥ��
LONG
    );

    set("exits", ([
	"north" : __DIR__"liangong",
	"south" : __DIR__"houting",
	"northeast" : __DIR__"xiulian",
	"west" : __DIR__"chufang",
    ]));

	set("no_fight", 1);
    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
}
