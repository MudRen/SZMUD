#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ͤ");
    
	set("long", @LONG
����һ�����ɱ��µ�Сͤ�ӣ��������ᣬ��Χ�������ƣ�ƮƮ���죬
�·��ɾ�һ�㣬͸������������ȥ��һ������Լ�ɼ�����ͤ������ڷ���
һ�Ŵ���ʯ������Χ�м���ʯ�ʣ�һ��ʯ���������һ��С���ӣ�board�� 
�Ա߱�ī�Ѿ������ˡ�
LONG); 

	set("exits", ([
		"northwest" : __DIR__"yitian",
	]));
	set("no_fight", "1");
	set("cost", 1);
	setup();
    
	call_other("/clone/board/tingyu_b", "???");
}

void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "��������ͤ���ֻ�����Ļ����ң�ȫ������Ҳ�޷�����������\n");
        return 1;
}
int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "����վ������ȴ���û�����ȫ���᲻��һ˿������������\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "��ֻ�����Դ��﷢�Σ��鱾��һ�����ֶ�������ȥ����Ҳ������ȥ��\n");
        return 1;
}