// Code of ShenZhou
// snake_room.h �߹������ߵķ���

void python_attack(object);

#include <ansi.h>

void init()
{
	object me, here;

	string *msg = 
	({
		HIR"���ߵ����ͻȻ�����й��ȳ�����ζ����\n"NOR,
		HIR"���������һ��uɳɳ�v��ϸ�����죬��������˾�����\n"NOR,
		HIR"��һ�ߵ���ط���ͻȻ�е�����������\n"NOR,
	});

	me = this_player();
	here = this_object();

	me->set("enter_shegu", 1);
	me->add("jingli", -5);

	if( time() - here->query("last_comeout") > 180 || !here->query("last_search")  )
		here->set("hide_python", 1 );


	if( random(query("hide_python") + 1 ) != 0 && me->query("race") != "����") {
		remove_call_out("python_attack");
		call_out("python_attack", 6+random(3), me); 
		if( me->query("family/family_name") == "����ɽ" ) 
		tell_object(me, msg[random(sizeof(msg))]);
	}
}

void python_attack(object me)
{
	object python, here;
	here = this_object();

	if ( environment(me) != here) return;

	if ( query("hide_python") < 1) return;

	add("hide_python", -1);
	python = new("/d/baituo/npc/bt_python");
	python->move(here);
	set("last_comeout", time() );

	message("vision", HIR"���Ȼ�ŵ�һ���ȷ磬�ͼ�һ��"+python->name()+HIR"���˳�����¶�����������"+me->name()+"ҧȥ��\n"NOR, environment(me), me);
	tell_object(me, HIR"����к���˻˻���죬һ���ɼ䣬����ȳ�ӭ�棬һ��"+python->name()+HIR"���Դܳ�����Ȼ�����ſ�������\n"NOR);

	python->kill_ob(me);

}
