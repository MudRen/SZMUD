void init()
{
	object me = this_player();
        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
	if (getuid(me) == "lisser" || wizhood(me) == "(admin)" || wizhood(me) == "(arch)" ){
		add_action("do_renwu","renwu");
		add_action("do_renwu","fenpei");
	}
	set("long", update_here());
}
string auto_e(string text)
{
	string newtext;
        newtext = replace_string(text, "+", "\n");
        return newtext;
}

int do_renwu(string arg)
{
	string grp_c, grp_n, grp_rw, grp_f;
	string wiz_c, wiz_n, wiz_rw, wiz_f;
	string i, stat, text;
	object wiz_data, me = this_player();
	if(!wiz_data=find_object("/clone/wiz/wiz_fpq"))
		wiz_data=new("/clone/wiz/wiz_fpq");
		
	if (!arg || arg == "") return notify_fail ("��ʽ���ԣ�������renwu help��\n");
	
	if ( arg == "help"){
		write(HIW"\n\nrenwu �����ʽ���£�\n");
		write("renwu ���Ŵ��� ��������                 ------->�趨���š�\n");
		write("renwu ���Ŵ��� �������� -sr             ------->�趨���ŵ�����\n");
		write("renwu ���Ŵ��� �������� -spr            ------->�趨���ŵ�������ҿɼ�����\n");
		write("renwu ���Ŵ��� ���Ź��������� -jc     ------->�趨���ŵ���������\n");
		write("renwu ���Ŵ��� ���Ź��������� -jpc    ------->�趨���ŵ�����������ҿɼ�����\n");
		write("renwu ID ���Ŵ��� ְ��                  ------->�趨�ò��ŵĳ�Ա��\n");	
		write("renwu ID ���Ŵ��� ���� -sr               ------->�趨�ò��ų�Ա����������������������\n");
		write("renwu ID ���Ŵ��� ���� -spr              ------->�趨�ò��ų�Ա������������������������ҿɼ�����\n");
		write("renwu ID ���Ŵ��� ������ -jc           ------->�趨�ò��ų�Ա��������������\n");
		write("renwu ID ���Ŵ��� ������ -jpc          ------->�趨�ò��ų�Ա����������������ҿɼ�����\n");
		write("renwu ���Ŵ��� delgrp                   ------->ɾ�����ŵ��������ϡ�\n");
		write("renwu ���Ŵ��� ID delcy                          ------->ɾ���ó�Ա����ݡ�\n"NOR);	
		write("renwu ID delwiz                         ------->ɾ���ó�Ա����������\n\n"NOR);	
		return 1;
	}
	if( sscanf(arg, "%s %s %s %s", wiz_c, grp_c, wiz_f, stat) == 4 ){
		text = setcolor(wiz_f);
		if (stat == "-jc"){
        		wiz_data->set_wizard_yinxiang(wiz_c, setcolor(wiz_f), grp_c, 1);
			tell_object(me, wiz_c+"�������������趨Ϊ"+setcolor(wiz_f)+"��\n");
		}else if (stat == "-sr"){
        		wiz_data->set_wizard_renwu(wiz_c, auto_e(text), grp_c, 1);
			tell_object(me, wiz_c+"�������趨Ϊ"+auto_e(text)+"��\n");
		}if (stat == "-jpc"){
        		wiz_data->set_wizard_yinxiang(wiz_c, setcolor(wiz_f), grp_c, 2);
			tell_object(me, wiz_c+"�������������趨Ϊ"+setcolor(wiz_f)+"����ҿɼ�����\n");
		}else if (stat == "-spr"){
        		wiz_data->set_wizard_renwu(wiz_c, auto_e(text), grp_c, 2);
			tell_object(me, wiz_c+"�������趨Ϊ"+auto_e(text)+"����ҿɼ�����\n");
		}else return notify_fail("��ʽ���ԣ�������renwu help��\n");
        }else if( sscanf(arg, "%s %s %s", grp_c, grp_f, stat) == 3 ){
		text = setcolor(grp_f);
		if (stat == "-jpc"){
        		wiz_data->set_group_yinxiang(grp_c, setcolor(grp_f), 2);
			tell_object(me, grp_c+"���ŵ������������趨Ϊ"+setcolor(grp_f)+"����ҿɼ�����\n");
        	}else if (stat == "-spr"){
        		wiz_data->set_group_renwu(grp_c, setcolor(grp_f), 2);
			tell_object(me, grp_c+"���ŵ������趨Ϊ"+auto_e(setcolor(wiz_f))+"����ҿɼ�����\n");
		}if (stat == "-jc"){
        		wiz_data->set_group_yinxiang(grp_c, setcolor(grp_f), 1);
			tell_object(me, grp_c+"���ŵ������������趨Ϊ"+setcolor(grp_f)+"��\n");
        	}else if (stat == "-sr"){
        		wiz_data->set_group_renwu(grp_c, auto_e(text), 1);
			tell_object(me, grp_c+"���ŵ������趨Ϊ"+auto_e(text)+"��\n");
		}else if (stat == "delcy"){
        		wiz_data->delete_wizard_chengyuan(grp_c, grp_f);
			tell_object(me, grp_c+"��"+grp_f+"�ĳ�Ա��ݱ�ɾ���ˡ�\n");
		}else{
			wiz_data->set_group_chengyuan(grp_f, setcolor(stat), grp_c);
			tell_object(me, setcolor(grp_c)+"��Ϊ"+setcolor(grp_f)+"��"+setcolor(stat)+"��\n");
		}
	}else if( sscanf(arg, "%s %s", grp_c, grp_n)==2 ){
		if (grp_n == "delgrp"){
        		wiz_data->delete_group(grp_c);
			tell_object(me, grp_c+"���ű�ɾ���ˡ�\n");
		}else if (grp_n == "delwiz"){
        		wiz_data->delete_wizard_renwu(grp_c);
			tell_object(me, grp_c+"������ɾ���ˡ�\n");
		}else{
	        	wiz_data->set_group(grp_c, setcolor(grp_n));
			tell_object(me, grp_c+"���ŵ������趨Ϊ"+setcolor(grp_n)+"��\n");
		}
        }else return notify_fail("��ʽ���ԣ�������renwu help��\n");
       	wiz_data->set_last(time());
	set("long", update_here());
       	return 1;
}
string update_here()
{
	object wiz_data, me = this_player();
	if(!wiz_data=find_object("/clone/wiz/wiz_fpq"))
		wiz_data=new("/clone/wiz/wiz_fpq");
	return HIC"��������ʦ���������ң���������ܶ�����ʾ�������������ܵ�д����\n"
		"ְ��ʦ�����֣����ڵĹ����飬��Ӧ������\n\n"NOR
		+wiz_data->query_wizard_yinxiang(me)+"\n\n"
		+wiz_data->query_time()+"\n";
}
