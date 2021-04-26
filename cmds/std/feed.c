// Code of ShenZhou
// feed.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest;
	int time;
        time = ((me->query("mud_age"))-(me->query("pktime")));

	if(!arg) return notify_fail("��Ҫιʲô������˭��\n");

	if( sscanf(arg, "%s to %s", item, target)!=2 )
		return notify_fail("��Ҫι˭ʲô������\n");

	if( !objectp(dest = present(target, environment(me))) )
		return notify_fail("����û������������\n");

	if( !dest->is_character() )
		return notify_fail("�����������ǻ��\n");

	if( dest->query("race") == "����" )
		return notify_fail("�㲻�����ⶫ��ι�ˣ�\n");

	if( !(obj = present(item, me)) )
		return notify_fail("������û������������\n");

	if( userp(me) && userp(obj) && me->query_condition("pker") > 240)
		return notify_fail("��е�һ˿�ھΣ���ͻȻ����������\n");
			
        if( (time < 3600) && userp(obj))
                return notify_fail("���Ծ�ɱ��̫�أ�������������\n");	
	
	if (!living(obj) && obj->is_character() &&
	!obj->query("food_supply") && dest->query("race")=="Ұ��" ) 
	{
                if (obj->query("disable_type") == "<˯����>"
                && random(obj->query_con()) > 3 
		&& dest->query("name") != "�ϻ�" 
		&& obj->query("combat_exp") > random(dest->query("combat_exp")))
 {
                     obj->revive();
                     obj->move(environment(me));
		     obj->receive_wound("qi", (int)(obj->query("eff_qi")/2));	

message_vision("$n��ͷ��"+dest->name()+"ҧ��һ�ڣ�$n��ʱ�۵����˹�����\n", me, obj);
                     obj->kill_ob(me);
		     obj->kill_ob(dest);	
                     return 1;
                } 
}
	if (!living(obj) && obj->is_character() && !obj->query("food_supply") && dest->query("race")=="Ұ��" ) {
		if (obj->query("disable_type") == "<˯����>"
		    && random(obj->query_con()) > 10) {
		     obj->enable_player();
		     obj->move(environment(me));
		     message_vision("$N���$n��ͷι��" + dest->name()+"�ԣ�$nͻȻ���ѣ�\n", me, obj);
		     obj->kill_ob(me);
		     return 1;
	        } else {
		     message_vision("$N��$n��ͷι��" + dest->name()+"���ˡ�\n",  me, obj);
		     if (userp(obj) && userp(me) )
			me->apply_condition("pker", me->query_condition("pker")+120);
		     obj->set_temp("last_damage_from", "��" +me->name()+"ι��" + dest->name()+"��");
		     obj->die();
		     return 1;
		}
	}

	if( obj->query("food_supply") <= 0 || obj->query("food_race") != dest->query("race") )
		return notify_fail("�㲻�����ⶫ��ι����\n");

	if (!obj->query("food_remaining"))
		return notify_fail(obj->name() + "�Ѿ�ûʲô��ι���ˡ�\n");

	if( dest->query("food") >= dest->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

	dest->add("food", obj->query("food_supply"));
	dest->add("jingli", obj->query("food_supply"));
	if( dest->query("jingli") > dest->query("max_jingli")) 
	dest->set("jingli", dest->query("max_jingli"));

//	if (obj->query("food_remaining")>4) obj->set("food_remaining",4);
	obj->add("food_remaining", -1);
	if (!obj->query("food_remaining") ) {
		message_vision("$Nι��" + dest->name() + "������" + obj->name() +"��\n",  me);
		destruct(obj);
	}
	else 
	message_vision("$N����" + obj->name() + "ι��" + dest->name() + "���˼��ڡ�\n", me);

	if( dest->is_fighting() ) dest->start_busy(2);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : feed|wei <ʳ������> to <ĳ����>
 
���ָ��������㽫ĳ��ʳ��ι��ĳ����ʳ�ã���Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
