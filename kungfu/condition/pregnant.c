// Code of ShenZhou
// pregnant.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object ob; 
	string result;
	int dura;
	dura = me->query_condition("pregnant");
	if(dura > 1000 && random(6) == 1){
		tell_object(me,HIY"��������岻�ʣ�ֻ����Щ÷��֮����ᶫ���ԡ�\n"NOR);
	}
	if(dura > 700 && dura < 1000 && random(6) == 1){
		tell_object(me,HIY"��Ż��һ����ˮ��ֻ������һ�󷳶�\n"NOR);
	}
	if(dura > 400 && dura < 700 && random(6) == 1){
		tell_object(me,HIY"������������ִ��ж��������㡣\n"NOR);
	}
	if(dura > 300 && dura < 400 && random(6) == 1){
		tell_object(me,HIY"����ø��������������������������ɬ�������ۡ�\n"NOR);
	}
	if(dura > 100 && dura < 300 && random(6) == 1){
		tell_object(me,HIY"����ø��е�С����������������Ķ��ӣ����Сԩ�ң��������ˣ�\n"NOR);
	}
	if(dura > 50 && dura < 100 && random(6) == 1){
		tell_object(me,HIY"�㸹��һ���ʹ��������Ҫ���ˣ�\n"NOR);
	}
	if(dura > 10 && dura < 50){
		switch(3)
		{	
			case 1:
			case 2:
			case 3:
				
message_vision(HIR"$Nֻ������������ʹ����Ҳ֧�ֲ�ס�������ڵأ��ʹ����˹�ȥ��\n"NOR,me);
				ob = new("/u/kane/baby");
				break;
		}
		me->apply_condition("pregnant",1);
	}
//	printf("%d\t%d\n",duration,dura);
	me->apply_condition("pregnant", duration - 1);
	if( !duration ) return 0;

	return CND_CONTINUE;
}

void create() {
	seteuid(getuid());
}
