// Code of ShenZhou
private int qi_damage_300(object me, object target)
{
	string msg1, skill = target->query_skill_mapped("force");
	int time;

	if ( skill == "" ) return 1;

	target->map_skill("force");
	target->set_temp("dugu/force", 1);
	time = (int)me->query_skill("sword") / 30;
	msg1 = RED "$pֻ���������������������������ѿأ���Ȼ����ʩչ"+to_chinese(skill)+"��\n" NOR;
	target->apply_condition("jiujian_qi_damage", time);
	message_vision(msg1, me, target);

	return 1;
}

private int qi_damage_220(object me, object target)
{
	int level, level1;
	string msg1, skill = target->query_skill_mapped("force");

	switch ( skill ) {
	   case "hunyuan-yiqi":
		if ( target->query_temp("jinzhongzhao") ) {
		   target->delete_temp("jinzhongzhao");
        	   msg1 = RED "$p���ﱻ�̣���ɫͻת�԰ף���ղ�������ͨ��Ȼ�߽⣡\n" NOR;
		}
		
		break;

	   case "hamagong":
		level = target->query_skill("force");
		msg1 = RED "$p��������ͥ��";

		if ( target->query_temp("reverse") ) {
		   target->add_temp("apply/dodge", -level/2);
		   target->set_temp("dugu/reverse", 1);
		   msg1 += "$p����ɢ�ң��Ѳ�����ʩչ������ת��ֻ�÷���ֱ��������\n";
		}

		if ( target->query_temp("powerup") ) {
		   target->add_temp("apply/attack", -level/4);
		   target->add("eff_qi", -level*5/2);
		   target->add("qi", -level);
		   target->set_temp("dugu/hamapowerup", 1);
		   if ( target->query_temp("reverse") ) msg1 += "ͬʱ";

		   msg1 += "$p�����޷����ۣ�˫�۷��飬��Ҳʹ������󡹦����\n" ;
		}

		msg1 += NOR;

		break;

	   case "huntian-qigong":
		level = target->query_skill("force");
                msg1 = RED "$p������������";

		if ( target->query_temp("powerup") ) {
		   target->add_temp("apply/dodge", -level/3);
		   target->add_temp("apply/attack", -level/3);
                   target->set_temp("dugu/powerup", 1);
                   msg1 += "$p�ؿ������Ĵܣ����Կ��ƣ��޷�����ʹ��������������\n"; 
                }

		if ( target->query_temp("shengang") ) {
		   target->set_temp("shengang", level/8);

		   if ( target->query_temp("powerup") ) msg1 += "ͬʱ";
		   msg1 += "$p����ͻ����й���������ģ�Ψ�п�ʼ������������\n";
		}

		msg1 += NOR;

		break;

	   case "longxiang-banruo":
		level = target->query_skill("force");

		if ( target->query_temp("shielded") ) {
                   target->add_temp("apply/armor", -level/2);
                   target->add_temp("apply/defense", -level/2);
                   target->set_temp("dugu/shield", 1);
		   msg1 = RED "$p�ٻ㱻�̣�ȫ������ͻй��������һɢ�����ǵ�����Ҳƽ��������\n" NOR;
                }

		break;

	   case "bitao-xuangong":
		level = target->query_skill("qimen-dunjia",1);
		
		if ( target->query_temp("wuzhuan") ) {
		   target->add_temp("apply/dodge", -level/5);
		   target->add_temp("apply/dexerity", -level/10);
		   target->add_temp("apply/speed", -level/30);
		   target->set_temp("dugu/wuzhuan", 1);
		   msg1 = RED "$p���б��̣�������ת���ͣ��Ų�򩺩��������ת��Ȼ��ȥ��\n" NOR;
		}

		break;

	   case "linji-zhuang":
		level = target->query_skill("linji-zhuang", 1);
		msg1 = RED "$p���������ţ�" ;

		if ( target->query_temp("linji/tiandi") ) {
		   target->add("max_qi", -level);
		   target->add("max_jing", -level);
		   target->add("max_jingli", -level);
		   target->receive_damage("qi", level, "ǿ�����ׯ�濹����ʽ������͸֧��������");
		   target->receive_damage("jing", level, "ǿ�����ׯ�濹����ʽ������͸֧��������");
		   target->receive_damage("jingli", level, "ǿ�����ׯ�濹����ʽ������͸֧��������");
		   if ((int)target->query("eff_qi") > (int)target->query("max_qi") )
			target->set("eff_qi", (int)target->query("max_qi") );
		   if ((int)target->query("eff_jing") > (int)target->query("max_jing") )
			target->set("eff_jing", (int)target->query("max_jing") );
		   target->set_temp("dugu/tiandi", 1);

		   msg1 += "$pֻ������Ѫ�����ڣ����Լ�Ԧ���޷����������ׯ��\n" ;
		}

		if ( target->query_temp("linji/zhixin") ) {
		   level1 = target->query_int() - target->query("int") - target->query_skill("literate", 1);
		   target->add_temp("apply/intelligence", -level1);
		   target->set_temp("dugu/zhixin", level1);
		   msg1 += "$p�����Ѷ���˼ά�������£�֮��ׯ���޷�������\n" ;
		}
	
		if ( target->query_temp("linji/fengyun") ) {
		   target->add_temp("apply/dexerity", -level);
		   target->add_temp("apply/attack", level);
		   target->set_temp("dugu/fengyun", 1);
		   msg1 += "ͬʱ$p���𽥻����������ɼ�����ׯ�ѱ��ƽ⣡\n" ;

		}

		if ( target->query_temp("linji/daxiao") ) {
		   level1 = target->query("max_qi") - target->query("max_jing");
		   if ( level1 < 0 ) level1 = 0;
		   level1 = level1 * level/400 ;
		   target->add("max_qi", -level1);
		   target->add("max_jing", level1);
		   target->receive_curing("jing", level1);
		   if ( (int)target->query("eff_qi") > (int)target->query("max_qi") ) 
                	target->set("eff_qi", (int)target->query("max_qi") );
		   target->set_temp("dugu/daxiao", level1);
		   msg1 += "���$p����ƣ̬���ƺ��������̣���СׯҲ����ʩչ�ˣ�\n" ;
		}

		msg1 += NOR;

		break;

	   default:
	  	msg1 = "";
	
		break; 
	}

	message_vision(msg1, me, target);
	if ( target->query_temp("dugu") && !target->query_condition("jiujian_qi_damage") ) { 
		target->apply_condition("jiujian_qi_damage", 1);
	}

	return 1;
}

private int qi_damage_150(object me, object target)
{
	string msg1;

	msg1 = RED "���$p�˱ܲ������н����������������\n" NOR;

	if ( random(2) == 1 ) {
	   target->add("max_neili", -(random(4)+2));
	}
	else {
	   target->add("neili",-(random((int)me->query_skill("dugu-jiujian"))*2));
	}

	message_vision(msg1, me, target);

	return 1;
}
