// Code of ShenZhou
// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "����ɽǰԺ");
        set("long", @LONG
���ǰ���ɽׯ��ǰԺ��Ժǽ��ש���ߣ����������·��޵ġ�Ժ��������
��������ݲ��������洫����˻˻�������죬���洫�����㣬������ׯ����
��������������ɽȥ����ɽ�š�
LONG
        );
        set("exits", ([ 
            "eastdown" : __DIR__"btgate",
            "west" : __DIR__"btroom",
	    "north" : __DIR__"btbarn",
	    "south" : __DIR__"btkitchen",
        ]));
        set("objects", ([ 
            CLASS_D("baituo")+"/binu" : 1,
	    CLASS_D("baituo")+"/jiading" : 1,
         ]) );
	set("outdoors","xingxiuhai");
        replace_program(ROOM);
        setup();
}

