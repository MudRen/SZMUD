// Code of ShenZhou
// interfere killing function (dispatched by chat_msg)

int inter_killing()
{
	object ob, ob1, me; 
	me = this_object();
	ob = this_player();

	if( interactive(ob = this_player()) 
	&& environment(ob) == environment()){
	if ( ob1->query("family/family_name") == "������" 
	&& ob->query("family/family_name") != "������"  
	&& ob->is_killing(ob1)){
	
	message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ����ҵ�������ɱ�ˣ����������ɺ��۸�ô��\n", me);
	command("follow " + ob->query("id"));
	me->kill_ob(ob);
	return;
	}
	}
}
