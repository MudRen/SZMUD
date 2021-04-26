
// ������¼��������õ�..
// Ŀǰ֧Ԯ�İ��:
// dragon ����
// moon ����
// sky ��ػ�
// info:
// ([
//    level:
//    title:
//    info1:
//    info2:
//    info3:
// ])

#pragma save_binary
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;

mapping club_record;
mapping club_leader;

private mapping club_detail = 
([
	"dragon" :      ([
				"name" :        "������",
				"mark" :        "dragon necklace",
				"file" :        "/d/obj/club/dragon_mark",
			]),

      "tianxia" :         ([
				"name" :        "���»�",
				"mark" :        "tianxia ling",
				"file" :        "/open/always/sky_mark",
				"file" :        "/d/obj/club/tianxia_mark",
			]),


]);

string *do_sort_record(string type,string *keys);
void resort_record();

void create()
{
	seteuid(getuid());
	if( !restore() )
	{
		club_record=([]);
		club_leader=([]);
	}
	else
	{
		if( !mapp(club_record) ) club_record = ([]);
		if( !mapp(club_leader) ) club_leader = ([]);
		club_detail=([
			"dragon" :      ([
						"name" :        "������",
						"mark" :        "dragon necklace",
						"file" :        "/d/obj/club/dragon_mark",
					]),

		]);
	}
}

string query_save_file() { return DATA_DIR + "club"; }

varargs string show_club_members(string type)
{
	string list="",*club_name,*member_id;
	int i,j,k;
	club_name=keys(club_record);
	if(type=="all")
	{
		for(i=0;i<sizeof(club_name);i++)
		{
			list=sprintf("%s%s:\n",list,club_name[i]);
			member_id=keys(club_record[club_name[i]]);
			k=0;
			for(j=0;j<sizeof(member_id);j++)
			{
				list=sprintf("%s  %12s",list,member_id[j]);
				k++;
				if(k%5==0) list+="\n";
			}
		}
	}
	else
		if(member_array(type,club_name)!=-1)
		{
			member_id=keys(club_record[type]);
			k=0;
			for(j=0;j<sizeof(member_id);j++)
			{
				list=sprintf("%s  %12s",list,member_id[j]);
				k++;
				if(k%5==0) list+="\n";
			}
		}
		else
		{
			return "û�д˰���¼��\n";
		}
		
	list+="\n";
	return list;
}

void clear_all()
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<=wiz_level("(arch)") || !userp(ob) )
	{
		write("��û���㹻��Ȩ���������¼��\n");
		return;
	}
	write("������������еİ���¼��  ȷ��Ҫ�����(y/n)");
	input_to("comfirm_clear_all", ob);
}

private void comfirm_clear_all(string yn, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("ȡ����\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) ������еİ���¼��\n������Ѷ:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), show_club_members("all")) );
	
	club_record=([]);
	save();
	write("�����Ѷ��ȫ��ɾ����\n");
	return;
}

void clear_record(string club)
{
	string *clubs;
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("��û���㹻��Ȩ���������¼��\n");
		return;
	}
	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("Ŀǰû�а���¼��\n");
		return; 
	}
	clubs=keys(club_record);
	if(sizeof(clubs)<1 || member_array(club,clubs)==-1)
	{
		write("û���������¼��\n");
		return;
	}
	
	write("���������"+club+"�İ���¼��  ȷ��Ҫ�����(y/n)");
	input_to("comfirm_clear",club, ob);
}

private void comfirm_clear(string yn,string club, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("ȡ����\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) ��� %s �İ���¼��\n������Ѷ:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , show_club_members(club)) );
	
	club_record[club]=([]);
	save();
	write("["+club+"]�����Ѷ��ɾ����\n");
	return;
}

void remove_club(string club)
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("��û���㹻��Ȩ���������¼��\n");
		return;
	}
	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("Ŀǰû�а���¼��\n");
		return; 
	}

	if(undefinedp(club_record[club]))
	{
		write("û���������¼��\n");
		return;
	}
	
	write("���������"+club+"��ᣡ  ȷ��Ҫ�����(y/n)");
	input_to("comfirm_remove",club, ob);
}

private void comfirm_remove(string yn,string club, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("ȡ����\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) ɾ�� %s ��ᡣ\n������Ѷ:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , show_club_members(club)) );
	
	map_delete(club_record, club);
	save();
	write("["+club+"]�����ɾ����\n");
	return;
}

int add_club(string club)
{
	object ob;
	ob=this_player();
        if( wiz_level(ob)<wiz_level("(immortal)") || !userp(ob) )
	{
		write("��û���㹻��Ȩ�����Ӱ�ᣡ\n");
		return 0;
	}

	if(!undefinedp(club_record[club]))
	{
		write("�Ѿ����������ˡ�\n");
		return 0;
	}
	club_record[club]=([]);
	write("�������OK��["+club+"]\n");
	save();
	return 1;
}

mapping query_club_record(string club)
{
	if(!undefinedp(club_record[club]))
	{
		if(mapp(club_record[club])) return club_record[club];
		else return ([]);
	}
	else return ([]);
}

string query_club_mark(string club)
{
	if(!undefinedp(club_detail[club]))
	{
		if(!undefinedp(club_detail[club]["file"]) && stringp(club_detail[club]["file"]))
			return club_detail[club]["file"];
		else return "";
	}
	else return "";
}

mapping query_club_detail(string club)
{
	if(!undefinedp(club_detail[club]))
	{
		return club_detail[club];
	}
	else return ([]);
}

string query_club_leader(string club)
{
	if(!undefinedp(club_leader[club])) return club_leader[club];
	else return "�޴˰����Ǵ˰��δ�趨����\n";
}

void set_club_leader(string club,string id)
{
	object ob;
	ob=this_player();

	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("Ŀǰû�а���¼��\n");
		return; 
	}

	if(undefinedp(club_record[club]))
	{
		write("û���������¼��\n");
		return;
	}
	
	if( wiz_level(ob)<wiz_level("(arch)") && query_club_leader(club)!=getuid(ob) )
	{
		write("��û���㹻��Ȩ���趨������䣡\n");
		return;
	}
	club_leader[club]=id;
	save();
	write("���["+club+"]�����趨Ϊ["+id+"]...OK!\n");
	log_file( "CLUB", sprintf("[%s] %s(%s) �趨 %s ��������� %s��\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , id) );
	return;
}

int is_club_leader(object user)
{
	string *clubs;
	int i;
	clubs=keys(club_leader);
	for(i=0;i<sizeof(clubs);i++)
	{
		if(club_leader[clubs[i]]==getuid(user)) return 1;
	}
	return 0;
}

int set_member(string club,string id,mapping info)
{
	string *clubs;
	clubs=keys(club_record);
	if(member_array(club,clubs)==-1)
	{
		notify_fail("û��"+club+"������!!\n");
		return 0;
	}
	club_record[club][id]=info;
	save();
	return 1;
}

int add_member(string club_id,string member_id,mapping info)
{
	string *clubs;
	clubs=keys(club_record);
	if(member_array(club_id,clubs)==-1)
	{
		notify_fail("û��������!!\n");
		return 0;
	}
	if(!undefinedp(club_record[club_id][member_id]))
	{
		notify_fail("������Ѿ�����˰����!!\n");
		return 0;       //�Ѿ��д˳�Ա
	}
	club_record[club_id][member_id]=info;
	save();
	return 1;
}

int remove_member(string club_id,string member_id)
{
	string *clubs;
	clubs=keys(club_record);
	if(member_array(club_id,clubs)==-1)
	{
		notify_fail("û��������!!\n");
		return 0;
	}
	if(undefinedp(club_record[club_id][member_id]))
	{
		notify_fail("���˲�û�м���������!!\n");
		return 0;       //�޴˳�Ա
	}
	map_delete(club_record[club_id], member_id);
	save();
	return 1;
}

int check_member(string club,string id)
{
	if(undefinedp(club_record[club]))
	{
		notify_fail("û��������!!\n");
		return 0;
	}
	if(undefinedp(club_record[club][id]))
	{
		notify_fail("���˲�û�м���������!!\n");
		return 0;
	}
	if(!undefinedp(club_record[club][id]["level"])) return (int)club_record[club][id]["level"]; //���ذ��ȼ�
	else return 1;
}

mapping query_member_info(string club,string id)
{
	mapping info;
	if(!undefinedp(club_record[club][id]))
	{
		if(mapp(club_record[club][id])) return club_record[club][id];
		else return ([]);
	}
	return ([]);
}

string *club_members(string club)
{
	string *members;
	
	if(undefinedp(club_record[club]))
	{
		notify_fail("û��������!!\n");
		return ({"û�д˰��\n"});
	}
	
	members=keys(club_record[club]);
	return members;
}

string *find_player_club(string id)
{
	string *result=({}),*clubs;
	int i;
	clubs=keys(club_record);
	for(i=0;i<sizeof(clubs);i++)
	{
		if(!undefinedp(club_record[clubs[i]][id])) result+=({clubs[i]});
	}
	return result;
}

object *find_online_members(string club)
{
	object *user,*result=({});
	string *club_member=({""});
	int i;
	club_member=club_members(club);
	user=users();
	for(i=0;i<sizeof(user);i++)
	{
		if(member_array(getuid(user[i]),club_member)!=-1) result+=({user[i]});
	}
	return result;
}
