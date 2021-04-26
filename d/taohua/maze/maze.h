// Code of ShenZhou
// Room: 
// Date: 

#include <ansi.h>
#include "localtime.h"

int check_count(object me, int count)
{
	int age,tmp1,tmp2,tmp, lvl, qmdj;
	mixed *local;

	age = (int)me->query("age");
  	local = localtime(((int)me->query("birthday")-14*365*24*60)*60);
  	tmp1 = (local[LT_YEAR]%10+local[LT_YEAR]%12+local[LT_MON]+local[LT_MDAY])%8;
  	tmp2 = (((local[LT_HOUR]+1)%24)/2)%8;
  	tmp = tmp1*8 + tmp2;
	me->set_temp("test-sz",tmp);
  	qmdj = me->query_skill("qimen-dunjia", 1);
	lvl = 1+random(qmdj)/20;	

        if (tmp == count) {
	if (me->query_temp("taohua/count")==2080) {
		 tell_object(me,HIR"
���ܾ���ͻȻ���ģ�������������ͷ��һ����ѣ......
����һ����������ʧ�ˡ�
\n\n"NOR);
	if (!me->query("taohua_maze")){
//		if ( qmdj < 100) me->add("combat_exp",10000);
//		else me->add("combat_exp", qmdj*100);
		me->add("int",1);
//		me->add("max_neili",200);
		me->set("taohua_maze",age);
		me->delete_temp("taohua/count");
		me->move("/d/taohua/xiangzhong");
me->add("AddGift/th/int",1);
        log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)���һ���ʯ����� һ�����ԡ�\n",
                ctime(time())[0..15], me->query("family/family_name"), me->name(), geteuid(me)));
        	log_file("Taohua",sprintf("%s(%s) passed Taohua Maze on %s. \n",
                        me->name(), getuid(me), ctime(time())));
	} 
/*	else if ( qmdj >= 100 ) {
		me->add_temp("apply/intelligence", lvl);
		me->add("taohua_maze2",1);
		call_out("remove_effect", lvl*200, me, lvl);
	} 
*/
	}
	else {
		tell_object(me,HIW"
�����һ�飬�������������·�׹......
�����ʶ����ģ������......
\n\n"NOR);
	    		me->unconcious();
			me->delete_temp("taohua/count");
			me->move("/d/taohua/enter_m");
	}
	} 
	else if (me->query_temp("/taohua/count/") > 2100) {
			tell_object(me, HIW"
������һ�������������������ܲ���
һ�������Ũ��˲������ס......
\n\n"NOR);
			me->unconcious();
			me->delete_temp("taohua/count");
			me->move("/d/taohua/enter_m");
	}
	return 1;
}

void remove_effect(object me, int level)
{
        me->add_temp("apply/intelligence", -level);
        tell_object(me, HIB"������һ�����Ժ��пտյ������ƺ���ʲ�ᶫ���������ȥ��\n"NOR); 
}
