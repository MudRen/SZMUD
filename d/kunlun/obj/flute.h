//Cracked by Roath
#define TRAVERSER "/clone/obj/traverser"

//int playing(object me);
//int halt_play(object me);
//void sound_float(object me, int range);

void init()
{
        add_action("do_play", "tan");
	add_action("halt_play", "halt");

}

string *tan_msg = ({
	HIM"�������������಻�ϣ�Խ��Խ�����������ߺ��ͣ��������棬ʵ������֮��������֮�����ƶ��ʡ�",
	HIG"���������ߺ��ͣ���ǰ���ᣬ����������ٿ�����ϣ��ƺ���ʮ���˷������ܣ�����˷��Ĵ���ϷŪһ�㡣",
	MAG"�������Ӷ��䣬��ǳЦ���Ƶ��ߣ�������ˡ�",
	HIG"ֻ����������������ת���������٣����Ǵ������衣",
	HIM"��ʱ��$w"+HIM"֮������Ʈ����������ת������һ��Ů��һ���̾Ϣ��һ���������һ����������´桢�����л���",
	HIM"$w"+HIM"�������ʲŸ��ӹ������ǣ�������ת������ϸϸ��ˣ��������ǻ��",
	HIG"$N��������֮����ֻ��������Խ��Խ�ߣ��������ǻس�������",
	HIM"$N����ͻת�������ı��������ˣ�ǡ�����ڷ��������˽�",
});

string *bihai_tan_msg = ({
	HIB"��ʱ�������糱ˮ����Ծ�����������Ϸ�ХŸ�ɣ��ټ���ˮ�����֣�ȺħŪ����������ɽƮ���������Ⱥ���У��������֮���¡�",
	BLU"��ʱ�����糱����ˮƽ�羵������ȴ���ǰ����ļ������������������գ����������߲�֪�������������Ϊ����ʤ����",
	HIB"���ﱾ�������ת��������ʱ������ȴ���߾�����ɱ֮�¡�",
	BLU"$N�ִ��ð��Σ�$w"+BLU"��������ϸ�������������š������ǡ��̺���������������֮�����������ᣬ��������",
});

string *succeed_msg = ({
	HIM"$n��ͷһ�������ϲ��Խ���¶��΢Ц��ֻ��ȫ����Ѫ���ڣ���ֻ�������㵸���Ҷ�һ�������������",
	HIM"$n������������ʱ�������������������ķ�����֮����������ͷ���ȣ�������",
	HIM"$n����һ��������һ����������һ��ֻ�������࣬Ѫ�����ţ����������㵸һ����",
	HIM"���������м���ħ����$n�ֵ���ס����������֮�£����е����ɽ��Ľ�����������ϡ�",
});

string *bihai_succeed_msg = ({
	HIB"$nֻ�����ҡ������������һ��һ����",
	HIB"$n��֧����һ�󣬺����������зɳ������⣬��ʱ���������������������������",
	HIB"$n���������֣����������ֹǣ��������к��⡣",
});

string *fail_msg = ({
	"$n�������������������㣬��ʱ������Ǳ��$f��������������",
	"����$n������տ����ͷ����һ��������Ӳ���������ȥ�����赸�������˻�����",
	"$n������������һƬ����������Ƭ������$N�����ٵ�������ֻ�뺣�в��Ρ����ҷ���һ�����졣",
	"$nֻ������һ�������Ϸ��ȣ���æ��������",
});

string *bihai_fail_msg = ({
	"����$n�������ܣ���Ԫ��һ��������־��$N����������ȴҲ���ܽ�$p������",
	"$n����������һ��ר�ز�����������������Ӧ��ԣ�磬ȴҲ������˿��������",
});

string *dazuo_fail_msg = ({
	"$n��ϥ���ڵ��£���ͷ�й��������������������ա�",
	"$n���ָ��أ����ַ��ڱ��ᣬǱ��$f���������񣬶�$N�Ĵ���ȫȻ���Ų�����",
	"$n��ϥ��������������������������ڻ����Լ���Ķ�������������",
	"$n��ϥ���ڵ��ϣ�һ������$f���������񣬵������������ա�",
});

string *faint_msg = ({
	HIM"������������ת��$n��Ҳ���Ͳ�ס������������������......",
	HIM"$n����Ƭ������������֮����ʧ�������������������......",
	HIM"$n����ȫ��ƮƮ���ɣ�����¶����㯶���������飬�鲻�Խ��������㵸����......\n",
});

int do_tan()
{
	int i, count, range;
	object me, ob, weapon;
        string msg, tan_type, *shape;

	ob = this_object();
	me = this_player();
	shape = ob->query("shape");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");
		
        if( me->query_skill_mapped("force") != "xuantian-wuji" )
         return notify_fail("����ʹ�ò��������ķ���\n");
	if( me->query_skill("force") < 120 )
                return notify_fail("����ڹ����Ƿ�ӣ�\n");

        if( (int)me->query_skill("qinqi-shuhua", 1) < 100 )
                return notify_fail("�������黭��򲻹���\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("�������������\n");

	if( !objectp(weapon = me->query_temp("weapon")) )
                return notify_fail("��û�д�����ε��ࡣ\n");

	if( weapon->query("name") != ob->query("name") )
		return notify_fail("�����в�û�����\n");

	for( i=0; i < sizeof(shape); i++ )
		if( shape[i] == "flute" )
		{
			count++;
			break;
		}

//	if( !count ) return notify_fail("�����в�û�����\n");
	
	
	if(me->query_temp("wuzhuan") && !me->query_temp("playing_bihai") )
	msg = "����$N��ɫ֣�أ��ְ�$n�����߱ߴ�������̤�Ű��Է�λ��";
	else msg = "$N$n�ʹ����������ʵĴ���������";
	if( environment(me)->query("no_fight") )
		msg += "�ⴵ�಻��˿�����������볣�˴������졣\n";
	else
	{
		msg += "\n";
		me->add("neili", -200);
		me->receive_damage("qi", 10);
                tan_type = "martial";
	}

	message_vision(msg, me, ob);
	me->set_temp("apply/short", ({ me->name() +"��������"+ ob->name() +"��"}));
        me->set_temp("tan_type", tan_type);

	message_vision(HIC"ͻȻ֮�䣬����������٣�����񣬷��˼����������������Ʈ��һ��������͵Ķ���������\n"NOR, me);
//	me->start_busy((: playing :), (: halt_play :));
	me->start_busy(2);
	call_out("playing", 1, me);
//		range = 1+(me->query_skill("bitao-xuangong", 1)-100)/4;
//		sound_float(me, range);
		me->set_temp("exercise/playing", 1);

	return 1;
}

void playing(object me)
{
	string play, succeed, fail, faint, map_force;
	int range, i, k=0, flag, music, music2, force, force2, tag, attacker, defender,damage,times;
	object *target, ob, env;
	
	env = environment(me);
	ob = me->query_temp("weapon");
	force = me->query_skill("force");
	music = (int)me->query_skill("music",1);
	times = me->query_temp("played_times");

	if(!me->query_temp("exercise/playing"))
	{
		message_vision(CYN"������ͣ������������Ϣ��һ��������������Ъ��\n"NOR, me);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}


	me->start_busy(2);

	if( !objectp(ob) )
	{
		message_vision(CYN"$N�������������ͣ��\n"NOR, me);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}
	if( me->query("jing") < 200 || me->query("neili") < 200 
	|| !living(me) || me->is_ghost())
	{
		if( me->query("jing") < 200)
			tell_object(me,"��ľ������Լ�������̺��������ˡ�\n");
		if( me->query("neili") < 200)
			tell_object(me,"������������Լ�������̺��������ˡ�\n");
		message_vision(CYN"������ͣ������������Ϣ��һ��������������Ъ��\n"NOR, me);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}

	target = all_inventory(environment(me));

		for(i=0; i<sizeof(target); i++) {
		if( !living(target[i]) || target[i]==me ) continue;
		k++;
		}

	if(k < 1 && !environment(me)->query("no_fight")) {
		tell_object(me,CYN"���²��޵��ˣ������ٴ���̺��������ˡ�\n"NOR);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}
	else {
		if(me->query_temp("wuzhuan") && !me->query_temp("playing_bihai") ) {

			me->set_temp("apply/short", ({ me->name() +"�ְ�"+ ob->name() +"������̤�Ű��Է�λ�����бߴ���"}));
			me->add_temp("playing_bihai",1);  //��Ϊ�̺�msg
		}

		//����playѶϢ���
		if(me->query_temp("playing_bihai") == 1) 
		play = HIC"��������ģ��󺣺��������޲���Զ����ˮ�����ƽ����������죬���������ӿ��������ɽ��";
		else if(!me->query_temp("playing_bihai")) 
                play = tan_msg[random(sizeof(tan_msg))];
		else 
                play = bihai_tan_msg[random(sizeof(bihai_tan_msg))] ;
		//end
		
		if(me->query("neili") < random(600)) message_vision(CYN"��������΢�����ͣ����漴�ع�ԭ����������\n"NOR, me);  //����play��


		if(times != 0 && times/2 * 2 == times)
			message_vision("", me);
		else message_vision("\n"+replace_string( play, "$w", ob->name() ) +"\n"NOR, me, ob);

		me->receive_damage("jing", 20+random(20), "����͸֧��������");

		if( environment(me)->query("no_fight") ) { //nofight-room no use
		call_out("playing", 1, me);
		return;
		}

		//playЧ������
		me->add_temp("played_times",1);

		if( this_object()->query("id") == "yu xiao" )
		flag = 2;
		else flag = 1;

		attacker = me->query("neili")/20 + random(force)/2+random(music*flag);

		if(me->query_temp("wuzhuan"))
		attacker = me->query("neili")/20 + random(force)/2+random(music*flag) + times*10;
		if( attacker <= 0 ) attacker = 0;
		//��ʼ�ظ��������е���
		for(i=0; i<sizeof(target); i++) {
		
		if( !living(target[i]) || target[i]==me ) continue;
					//����ѶϢ��� 2

		if(!me->query_temp("playing_bihai")) {
                play = tan_msg[random(sizeof(tan_msg))];
		succeed = succeed_msg[random(sizeof(succeed_msg))];
		fail = fail_msg[random(sizeof(fail_msg))];
		}
		else {
                play = bihai_tan_msg[random(sizeof(bihai_tan_msg))] ;
		succeed = bihai_succeed_msg[random(sizeof(bihai_succeed_msg))];
		fail = bihai_fail_msg[random(sizeof(bihai_fail_msg))];
		}
		faint = faint_msg[random(sizeof(faint_msg))];
		
		if(target[i]->query_temp("pending/exercise") || target[i]->query_temp("pending/respirate", 0))
		fail = dazuo_fail_msg[random(sizeof(dazuo_fail_msg))];
		
			//end

		tag = target[i]->query("married_times");
		if(tag > 20) tag = 20;
		music2 = (int)target[i]->query_skill("music",1);
		force2 = target[i]->query_skill("force");
		defender = target[i]->query("neili")/25 - tag*5 + random(force2) + music2;
		//����������ʱ�������
		if(target[i]->query_temp("pending/exercise") || target[i]->query_temp("pending/respirate", 0)) 
		defender = target[i]->query("neili")/10 - tag*10 + random(force2) + music2;

		if(defender < 1) defender = 1;

		if( times/2 * 2 != times && target[i]->query("family/family_name") == "�һ���" && music2 > music/2 ) {
			message_vision("$n��֪�������仯����$N������һ�����ǲ���Σ����\n"NOR, me, target[i]);
			}
		else if( attacker < defender ) {
		
		map_force = target[i]->query_skill_mapped("force");
		if (!target[i]->query_skill_mapped("force")) map_force = "force";
			if(target[i]->query("race") != "����" || times/2 * 2 == times )
			message_vision("", me, target[i]);
			else message_vision( replace_string( fail, "$f", to_chinese(map_force)) +"\n"NOR, me, target[i]);
			if (wizardp(me) && me->query("env/check_play"))
			tell_object(me,sprintf("attacker��%d ,defender��%d \n"
			,attacker,defender));
		}
		else {
			damage = force + music/3+ random(music/2)*flag + random(tag*10) + (-(int)target[i]->query("max_neili") / 30) + -random(force2/2) + -force2/3;
			if( damage > 600+flag*200 ) damage = 600+flag*200; // most ppl have at most 1k+ jing
			if( damage < 100 ) damage = 100;

			damage = damage + me->query_temp("playing_bihai")*8;
			
			if (wizardp(me) && me->query("env/check_play"))
			tell_object(me,sprintf("attacker��%d ,defender��%d ,damage��%d \n"
			,attacker,defender,damage));

			if( damage > 0 ) {
			target[i]->receive_damage("jing", damage, me);

			target[i]->add("jingli", -damage, me);
			target[i]->add("neili",-damage);
			target[i]->add_temp("be_played/"+me->query("id"),1);
			target[i]->start_busy(1);

			if (!target[i]->is_killing(me->query("id")) || !target[i]->is_fighting(me) || !me->is_fighting(target[i]))
			target[i]->kill_ob(me);

			//target[i]->set_temp("last_damage_from",me);
			//��ͬ�����˺���ͬ
			if(!me->query_temp("playing_bihai")) 
			target[i]->receive_damage("jing", random(damage/3 + tag*5), me);
			else target[i]->add("neili",-random(damage/2));
			//
			if( target[i]->query("neili") < 0)
				target[i]->set("neili",0);

			if((target[i]->query("jing") < 0 || target[i]->query("jingli") < 0 )
			&& target[i]->query("race") == "����") 
			message_vision( faint+"\n"NOR, me, target[i]);
			else if((target[i]->query("jing") < 0 || target[i]->query("jingli") < 0 ) && target[i]->query("race") != "����")
			message_vision("ֻ��$n������ͷ����������ҡͷ���Ե��趯��\n"NOR, me, target[i]);
			else if(times/2 * 2 == times)
			message_vision("", me, target[i]);
			else if(target[i]->query("race") != "����")
			message_vision("ֻ��$n������ͷ����������ҡͷ���Ե��趯��\n"NOR, me, target[i]);
			else message_vision( succeed +"\n"NOR, me, target[i]);
			}
			}
		}
		//playЧ�����㵽����

		if (wizardp(me) && me->query("env/check_play"))
			tell_object(me,sprintf("times��%d\n" ,times));

		if(me->query_temp("playing_bihai")) me->add_temp("playing_bihai",1); 
		me->add("neili", -100);
		env->set("playing", me);
		call_out("playing", 1, me);
		return;
	}
}

int halt_play()
{
	object me;
	me = this_player();
	if(me->query_temp("exercise/playing")) {
	message_vision(CYN"������ͣ������������Ϣ��һ��������������Ъ��\n"NOR, me);
	me->delete_temp("apply/short");
	me->set_temp("delete/playing");
	me->delete_temp("played_times");
	me->delete_temp("playing_bihai");
	me->delete_temp("exercise/playing");
	remove_call_out("playing");
	return 1;
	}
	else return 0;
}
