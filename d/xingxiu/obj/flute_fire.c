// Code of ShenZhou
// Ryu, 12/5/96

inherit ITEM;
#include <ansi.h>;

void init();
void wear(int);

int worn;

void create()
{
        set_name(HIR"һ�ѻ���"NOR,({"huo yan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR"�����Լ�ߣ�"+GRN+"ɫ�����̣�"+BLU+"����ɭɭ��"+HIR+"��Ѱ��������졣\n"NOR);
                set("unit", "��");
                set("value", 10000);
                set("no_get", 1);
                set("no_drop", 1);
        }
        
        setup();
}

void init()
{
        worn = 0;
        call_out("wear", 100, 1); 
        add_action("do_kick","ti");
        add_action("do_kick","kick");
}


int do_kick(string arg){

	object ob, me, armor;
	mapping myfam;
	int exp1, exp2;
	me=this_player();
	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));  
	
	if(!ob) return notify_fail("����û��������\n");
	
	exp1=me->query("combat_exp");
	exp2=ob->query("combat_exp");
	
	if(!ob->is_character() || !me->is_fighting(ob) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (me->is_busy()) return notify_fail("����æ���ء�\n");
	
	if ((me->query_skill("feixing-shu",1)<150)){
		message_vision(HIR"\n$N����һЦ������������������ȥ�����һ���ҽУ����������ˡ�\n"NOR,me);
		me->receive_wound("qi", random(500),"������");
		destruct(this_object());
		me->start_busy(random(2)+2);
		return 1;
	} else {
		
		me->add("neili",-me->query_skill("feixing-shu",1));
		message_vision(RED"\n$N��ɫһ�䣬����һ�Σ��Ѿ�ת��$n��󡣾����ҽţ�΢΢һ������������$n��ȥ��\n"NOR,me,ob);
		me->start_busy(random(2)+2);
		if(random(exp1)>random(exp2)){
		
			if( ob->query_temp("armor/cloth")){
				armor = ob->query_temp("armor/cloth");
                		if( armor->query("id") != "armor") {
                     			message_vision(HIR"\nֻ��$N���ϵ�$n"+HIY+"�������յ���ɢ���ɡ�\n"NOR, ob, armor);
                     			armor->unequip();
                     			armor->move(environment(ob));
                     			armor->set("name", "�ս���" + armor->query("name"));
                     			armor->set("value", 0);
                     			armor->set("armor_prop/armor", 0);
                     			ob->reset_action();
                		}
                	}
                	
			message_vision(HIR"\nֻ����һ���ҽУ�$n�������������������С�\n"NOR,me,ob);
			ob->receive_wound("qi", me->query_skill("feixing-shu",1),"������");
			ob->start_busy(random(2)+1);
			destruct(this_object());
			return 1;
		} else {
			message_vision(HIY"\n$n��֮�������������ֻ��$N΢΢��Ц��\n"NOR,me,ob);
			destruct(this_object());
			return 1;
		}
	}
	
}

void wear(int phase)
{
        worn = phase;
        switch(phase) {
        case 1:
                set("long", HIR"��������ȼ���ţ�"+GRN+"ɫ�����̣�"+BLU+"����ɭɭ��"+HIR+"��Ѱ��������졣\n"NOR);
                call_out("wear", 100, phase+1); 
                break;
        case 2:
                set("long", RED"����Խ��Խ���������������ˡ�\n"NOR);
                call_out("wear", 30, phase+1); 
                break;
        case 3:
                message_vision(RED"���潥����Ϩ���ˡ�\n"NOR, this_object());
                destruct(this_object());
                break;
        }       
}

// End of File 
