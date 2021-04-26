// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ȸ��");
        set("long", @LONG
�����µĴ���ȸ������й�����ǻƽ̵Ļ��̷���--�����������ֽ�
��ס���(statue)����Χ���ǻ�ɫΧ��(curtain)���������ж�ʮһ��ȶɷ�
ĸ��������ɱ֮����
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"frontyard",
        ]));
	set("item_desc", ([
              "statue" : "һ���������޺�����Χ��Ƥȹ��ͨ���ɫ�����ָ߾ٽ�ħ���������ֳ�������
��������������������֮�⡣������ǰ�������Ⱥ������������ϡ�\n",
              "curtain" : "һ���ȸ��ɫ��Χ�ʣ�����ȥ�Ѿ��ǳ��ĳ¾��ˣ����涼����ɫ�����������
����ħ���¡�\n",
	]));
	set("objects", ([
                "/d/xueshan/npc/xiangke" : 1,
        ]));
	set("cost", 1);
        setup();
}
void init()
{
        add_action("do_study","study");
}
int do_study(string arg)
{
	object me = this_player();
        int level, check;

	level = (int)me->query_skill("mingwang-jian",1);
        check = level*level*level;

	if( !arg || arg!="curtain" ) return 0;

	if ( (int)me->query_skill("longxiang-banruo", 1) < 20
	|| (int)me->query("combat_exp") < 10000
	|| (int)me->query_skill("lamaism", 1) < 30 ){
		write ("���ж���һ���Χ���ϻ��ͼ������������������ݶ�����˵̫����ˡ�\n");
	return 1;
	}	
	if ( (int)me->query_skill("mingwang-jian", 1) > 120){
		write("���ж���һ���Χ���ϻ��ͼ������������������ݶ�����˵̫ǳ�ˡ�\n");
	return 1;
	}	
	if ( check > (int)me->query("combat_exp")*10 ){
		write("���ж���һ���Χ���ϻ��ͼ������ʵս���鲻�㣬�����Ҳû�á�\n");
	return 1;
	} 
	if ( (int)me->query("jing") < 30 ){ 
		write("��ľ����ܼ��С�\n");
	return 1;
	}
	else {
        me->receive_damage("jing", 25);
        me->improve_skill("mingwang-jian", me->query("int"));
	if (me->query_skill("mingwang-jian", 1) > 50)
	me->receive_damage("jing", 10);
        	write("����ϸ�ж�Χ���ϵ�ͼ����\n");
	}
	return 1;
}	
