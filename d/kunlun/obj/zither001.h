//Cracked by shenzhou
void init()
{
43
        add_action("do_tan","play");
}

string *tan_msg = 
({
:        HIM"\n$N�������ף�ʮָ�Ӷ����ң���ʼ�����࣬���ְ������ң����ֵ�����������ʱ����֮�����죬��������\n�������������š�\n"NOR,
:        HIM"\n���������߿���������˿�����Ʈ����ȴ���಻���������س�����֮�⣬���д��뼸�����ĵĺ�������\n��������������̾Ϣ�����ƿ�����\n"NOR,
:        HIG"\n������������������ɪɪ����֮��������һ�ε�С��������Ҷ��$N��ָһ�ӣ������QȻֹЪ��\n"NOR,
:        MAG"\n����ֻ���������������Ŷ�����������ã�ͻȻ������������ȥ��Խ��Խ�ߣ���������֮����\n�һ���죬����һ�����ң��ٸ��˼��������һ���������ֶ���һ����\n"NOR,
	HIG"\n�������𣬵��˵��ң�ͣ��һ�ᣬ�����ڽ����˵����һ�ȥ���ֵ��˵��ң�������������\n������ԽתԽ�ߣ������Ͼ�Ȼ�������ģ��������ᣬ���������ı�ת����ȥ��\n"NOR,
	HIM"\n��һ��ʱ������������ʱ���������¡��������ã����Ͻ������ƺ������ڲ�סԶȥ��\n��������֮���߳�����ʮ��֮ң�����ߵ�����֮�⣬ϸ΢���������š�\n"NOR,
	HIM"\n��ʱ��������һ������̾Ϣ�������ǳ�¶���󻨰꣬����ͷ����ң�������ƽ��������\n��Ȼ������֮�⡣\n"NOR, 
});


int do_play()
{
	int i, count, range, skill;
	object me, ob, weapon;
        string msg, tan_type, *shape, family;

	ob = this_object();
	me = this_player();
	shape = ob->query("shape");
	skill = me->query_skill("qinqi-shuhua", 1);
	
	if (me->query("family/family_name"))
		family=me->query("family/family_name");
	
	if(skill < 60) 
	{
		message_vision(CYN"\n$N��������С�ĵ��ó���ƽ���ڰ���ʮָ��Ӳ��ѹ�������ϣ���ָ��Ū���ң���������! ����ѽѽ����������֮�� ��\n"NOR, me);
		tell_object(me,"\n��������黭�ȼ��������޷������ɿ������硣\n"NOR);
		me->add("jingli", -(10 + random(5)));
		return 1;
	}
	
	if ( !present("qupu", me))
                return notify_fail("������Լ�ʮָ�Ѿ����������Ѿ���һ���Ļ�����Ӧ���ұ���������ϰ�ˡ�\n");
		
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");
		
        if(! family || family != "������" && !wizardp(me))
               	return notify_fail("�㲢�����ص��ӣ�\n");
	
	if( me->query_skill("force") < 40 )
                return notify_fail("����ڹ����Ƿ�ѣ�\n");

        if( (int)me->query("neili") < 200 )
        	return notify_fail("�������������\n");
        	
        if( (int)me->query("jing") < 200 )
		return notify_fail("��ľ��񲻼ѡ�\n");
		
	if( (int)me->query("jingli") < 250 )
		return notify_fail("��̫���ˡ�\n");
	
	if( !objectp(weapon = me->query_temp("weapon")) )
                return notify_fail("��û�д�����ε��ࡣ\n");

	if( weapon->query("name") != ob->query("name") )
		return notify_fail("�����в�û�����١�\n");

	if (find_call_out("playing") >= 0) 
		return notify_fail("����ͬʱ������������\n");
	
		msg = "\n$N�ڳ���һ�Ź��ݣ����ض�������������������һʱ�䣬�����������Χ���˶�������һƬ����֮�У�\n";
	
	
	message_vision(msg, me, ob);
	message_vision(HIC"\nͻȻ֮�䣬���������������񣬷��˼����������������Ʈ��һ��������͵���������\n"NOR, me);
	me->start_busy(2);
	call_out("playing", 2, me, 0);
	return 1;
}

void playing(object me, int stage)
{
	int i, size, exp, pot, myexp, jingcost, jinglicost;
	size=sizeof(tan_msg);
	if( stage < size)
	{
		message_vision(tan_msg[stage], me);
		me->start_busy(2);
		call_out("playing", 2 , me, ++stage);
		
	}
	else 
	{
		message_vision("\n�����������������ͣ�ͻȻ�һ��������ֹЪ��$N�ḧ���ң�������վ��������\n", me);	
		myexp=me->query("combat_exp");
		exp = 6+random(3);
		pot = 4+random(2);
		jingcost= (int)((myexp/1000)*4);
		jinglicost = (int)((myexp/1000)*2);
		
		if (jingcost > 150) jingcost = 150;
		if (jinglicost > 200) jinglicost = 200;
		me->add("combat_exp", exp);
                if (me->query("potential") < me->query("max_potential"))
			me->add("potential", pot);
		me->add("jing", -jingcost);
		me->add("jingli", -jinglicost);
                  me->improve_skill("qinqi-shuhua", 25+random(10));
		log_file("/job/Kunlun_tan", ctime(time()) + me->query("name") +"(" + me->query("id") + ")���ٻ��" + exp + "�����"+ pot + "Ǳ��\n" );
	}
}
