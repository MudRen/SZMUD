// �����硤���μǣ���������WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string top_id, id;
	object ob;
	int ban;
	
	if( !arg || arg=="" )
		return help();

	if( sscanf(arg, "%s -u %s", top_id, id)==2 ) ban = 0;
	else if(sscanf(arg, "%s %s", top_id, id)==2 ) ban = 1;
	else return help();
	
	ob = find_player(id);
	if(!ob) ob = LOGIN_D->find_body(id);
	
	if(ban)TOPTEN_D->topten_del(id,top_id);
        else if(ob)TOPTEN_D->topten_add(ob, top_id);
	
        TOPTEN_D->do_ban(top_id,id,ban);
	write("ok.\n");
	return 1;
}

int help()
{
	write("\n��ָ������ȡ����ָ�һ����ҽ���ĳһ���а�\n���ʸ�." +
		"ָ���ʽ��tban top_id [-u] player_id\n" +
		"Ʃ��: \ntban exp misu��ȡ��misu����exp���а���ʸ�.\n" +
		"tban exp -u misu ��ָ�misu�������а���ʸ�.\n"
	);
	
	return 1;
}
