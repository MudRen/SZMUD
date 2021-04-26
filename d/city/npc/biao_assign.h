// Code of ShenZhou
string ask_biao()
{
	object ob = this_player();
	object me = this_object();
	object biao;
	mapping skill_status;
        string *sname, value, destin;
        int i, quali = 0;

	if ( ob->query("family/family_name") == "ؤ��" )
                return "��Ҫ���ĵ��������ʲô�����߿��ߣ�";

	if ( ob->query("biao_stealer") >= 1 ) {
		command( "sneer" );
		return "�������Ǽ��������Ե����������ŵù��㣿";
	}

	if ( (int)ob->query_temp("biao/fail") ) 
		return "���ⲻ���õļһ���㻹������������Ҫ�����ڣ�";

	if ( (int)ob->query_temp("biao/times") >= 5 )
		return "���Ѹ��˺ö�����������Ϣһ�°ɡ�";

	if ( (int)me->query_temp("biao") >= 20 )
		return "�������е��ڶ��������ˣ�������������ɡ�";

	if ( ob->query_temp("biao/pending") ) {
		command( "angry" );
		return "�㻹û�������͵��������ϣ���ô�����ֶ�׮���£�";
	}

	//Check qualifications to assign proper tasks.
	if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
			quali += skill_status[sname[i]];
		}	  

		quali = quali/sizeof(skill_status);

	}
	else {
		quali = 0;
	}

	if ( quali < 10 ) return "��������ƾ�㣿�����Ƚ�����������˵�ɡ�";

	command( "say �ðɣ�����������ʱ���������ȱ���á�");
	switch( random(5) ) {
		case 0:
			ob->set_temp("biao/zhu", 1);
			command("say �����ݶ����͵���¹��Ժ���������Ƕ�������ḶǮ���㡣");
			destin = "��¹��Ժ����";
			break;
		case 1:
			ob->set_temp("biao/bayi", 1);
			command("say ���Ǳ���С��İ�����ү���͵����ڣ���ö��С�ģ����˿��ⲻ��");
			destin = "����С�����";
			break;
                case 2:
			ob->set_temp("biao/ma", 1);
			command("say ����������͵�Ȫ��������ݵģ�������Խ��������������ʦ��");
			destin = "������������";
			break;
		case 3:
			ob->set_temp("biao/li", 1);
			command("say ���з�Ҫ�͸���ɽ������ȪԺ��������ڻ����������һ�˰ɡ�");
			destin = "��ȪԺ������";
			break;
                case 4:
			ob->set_temp("biao/jiang", 1);
			command("say ���ǵ����������������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ����ױ��ӳ�����ʤ���");
			destin = "̩ɽ����ʤ";
			break;
	}
			
	message_vision( "$n����$Nһ���ڻ���\n", ob, me );

	//player record
	ob->add_temp("biao/times", 1);
	ob->set_temp("biao/pending", 1);
	ob->set_temp("apply/short", ({"�ڿ� "+ob->name()+"("+ob->query("id")+")"}));

	//goods record
	biao = new("/d/city/obj/biaohuo1");
	biao->move(ob);
	biao->set_temp("guard", ob->query("id"));
	if ( ob->query_temp("biao/li") ) biao->set_temp("dest", "li");
	if ( ob->query_temp("biao/ma") ) biao->set_temp("dest", "ma");
        if ( ob->query_temp("biao/zhu") ) biao->set_temp("dest", "zhu");
        if ( ob->query_temp("biao/bayi") ) biao->set_temp("dest", "bayi");
        if ( ob->query_temp("biao/jiang") ) biao->set_temp("dest", "jiang");
	if ( quali < 30 ) {
		biao->set_temp("prop", 1);
		value = "��ͨ����";
	}
	else if ( quali < 60 ) {
		biao->set_temp("prop", 2);
		value = "��������";
	}
	else if ( quali < 90 ) {
		biao->set_temp("prop", 3);
		value = "�����Ʒ";
	}
	else if ( quali < 120 ) {
		biao->set_temp("prop", 4);
		value = "����֮��";
	}
	else if ( quali < 150 ) {
		biao->set_temp("prop", 5);
		value = "�亱����";
	}
	else if ( quali < 180 ) {
		biao->set_temp("prop", 6);
		value = "ϡ������";
	}
	else {
		biao->set_temp("prop", 7);
		value = "�޼�֮��";
	}

	//announce by rumor
	CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s������һ��%s��%s��", ob->name(), value, destin));

	//assigner record
	me->add_temp("biao", 1);

	switch( random(4) ) {
		case 0:
			return "��ν�������ڣ�������������������޶���ʱ�����������";
			break;
		case 1:
			return "һ·������ܻ���������ǿ������һ��Ҫ���С�ġ�";
			break;
                case 2:
			return "����������ң�����������ǧ�������������ھֵ����ֺţ�";
			break;
                case 4:
			return "����뾡�콫�ڻ��͵�������������ھֿ��ⲻ��\n";
			break;
	}
}
