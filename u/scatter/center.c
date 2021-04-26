//Code of ShenZhou (7/26/2001)

#include <ansi.h>
inherit ROOM;
#define JOB_DIR "/clone/obj/job/"
int JOB_TICK=5;
int JOB_PRODUCE=120;
int PRODUCE_TEMP=0;
string copyright=HBBLU+HIY+"��Ϸ����������쿴��1.0��     Server 2001��7��     \n"NOR;
string show_word();
#include "/clone/obj/job/default_data.h"
#include "/clone/obj/job/lpc_math.h"

#define MAPDB "/clone/obj/mapdb"
#define TRAVERSER  "/clone/obj/traverser"
#define JOB_DIR "/clone/obj/job/"

void create()
{
	set("short", HIR"���ֻþ�"NOR);
	set("long", HIC
"�����������и�����������ϵͳ�Ŀ������ģ���������Կ���������Ϸ\n"
"��ǿ��������ϵͳ���˵������֮�أ��������ڽ���ʵ���С�����һƬ\n"
"���ޣ������޷���������һ��\n"+NOR
HIY+"\t�Ϸ���մ�Ư���Ž�������ļ���С��(gold word)��\n"+NOR
	);
        set("outdoors", "����Ʈ��");

	set("exits", ([
		"kd" : "/d/city/kedian",
        
	]));
		set ("item_desc", ([
				"gold word" : (: show_word :),
				]));
		set("no_refresh",1);
	setup();

}

string show_word()
{
	return HIW"���ֻþ����ƴ󷨣�\n"NOR
		HIC"\t����\t\t\t����\n"NOR
		HIY"\tstart_system\t\t"NOR+HIG"��������ϵͳ\n"NOR
		HIY"\tclose_system\t\t"NOR+HIG"��������ϵͳ\n"NOR
		HIY"\tjob_start\t\t"NOR+HIG"����һ������\n"NOR
		HIY"\tjob_stop\t\t"NOR+HIG"ֹͣ���ֻþ�����ϵͳ\n"NOR
		HIY"\tjob_check\t\t"NOR+HIG"��ѯ��������ϵͳ����״̬\n"NOR
		HIY"\tjob_setorg_default\t"NOR+HIG"���������ɲ�������Ϊȱʡ\n"NOR
		HIY"\tjob_setorgluck\t\t"NOR+HIG"�޸�ĳ�����ɵ�������ֵ\n"NOR
		HIY"\tjob_setorgmoney\t\t"NOR+HIG"�޸�ĳ�����ɵĽ�Ǯϵ��\n"NOR
		HIY"\tjob_setorgstrategy\t"NOR+HIG"�޸�ĳ�����ɵĲ���ϵ��\n"NOR
		HIY"\tjob_setorgpower\t\t"NOR+HIG"�޸�ĳ�����ɵ�����\n"NOR
		HIY"\tset_contribute\t\t"NOR+HIG"�޸�ĳ�����ɵĹ��׶�\n"NOR
		HIY"\tdo_check_player\t\t"NOR+HIG"����ĳ����ҵ�����ִ�����\n"NOR
		HIY"\tjob_cut\t\t\t"NOR+HIG"ɾ��ĳ����ҵ�������Ϣ\n"NOR
		HIY"\tcheck_do_job\t\t"NOR+HIG"����Ŀǰ����������ҵ�����ִ�����\n"NOR
		HIY"\tchange_rate\t\t"NOR+HIG"�޸�Ŀǰ����ķ������\n"NOR
		HIY"\tcheck_menpai_job\t"NOR+HIG"�쿴Ŀǰ���ɵ�����������\n"NOR
		HIY"\tcheck_menpai_assess\t"NOR+HIG"�쿴���ɵĹ��׶����\n"NOR
		

		

		HIR"\n\n\t\t\t\t\t\����\n"NOR
		;
}
void init()
{
	object ob;

	add_action("do_start", "job_start");
	add_action("do_check_player", "do_check_player");
	add_action("do_stop", "job_stop");	
	add_action("do_check", "job_check");
	add_action("do_setorg_default", "job_setorg_default");
	add_action("do_setorg_luck", "job_setorgluck");
	add_action("do_setorg_money", "job_setorgmoney");
	add_action("do_setorg_strategy", "job_setorgstrategy");
	add_action("do_setorg_pwoer", "job_setorgpower");
	add_action("do_set_job_contribute", "set_contribute");
	add_action("do_cut_job", "job_cut");
	add_action("do_check_do_job", "check_do_job");
	add_action("do_change_rate", "change_rate");
	add_action("do_check_menpai_job", "check_menpai_job");
	add_action("do_start_system", "start_system");
	add_action("do_close_system", "close_system");
	add_action("do_check_menpai_assess", "check_menpai_assess");
}


//judge this system who can use it?
int can_used()
{
		object me;
		me=this_player();

		if(this_player()->query("id")!="buwu"&&
         this_player()->query("id")!="scatter"&&
         this_player()->query("id")!="lisser"&& 
			this_player()->query("id")!="troy"
            			)
			return notify_fail ("�������ϵͳĿǰֻ���ɸ߼���ʦ�����ơ�\n");
		if(!wizardp(me))
			return notify_fail ("�㻹û�л�����ɵķ������޷��������\n");
		return 1;

}
int do_check_menpai_assess()
{
	object menpai_ob,job_data;
	mapping *family_do_datas,*menpai,temp_map,temp1_map;
	string *family_name;
	int i;
	if(!can_used())
		return 0;
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	if(!objectp(menpai_ob)) return 0;
	menpai_ob->restore();
	menpai=menpai_ob->query_familys();
	if(!pointerp(menpai))
		return notify_fail ("menpai_data error!!!\n");

	
	family_name=get_array_map("family_name",menpai);

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();

	family_do_datas=job_data->query_familys_job_data();
	if(!pointerp(family_do_datas))
		return notify_fail ("family_do_datas\n");
	write(copyright);
	
	for(i=0;i<sizeof(family_name);i++)
	{
		//printf("%s\n",family_name[i]);
		temp_map=job_data->query_family_job_data(family_name[i]);
		if(!mapp(temp_map)
		||temp_map["job_contribute"]<=0||undefinedp(temp_map["job_contribute"]))
		{
			temp_map=([]);
			temp_map["job_contribute"]=0;
		}
	
		//continue;
		temp1_map=get_mapping(family_name[i],"family_name",menpai);
		if(!mapp(temp1_map)
		||temp1_map["family_assess_num"]<=0
		||undefinedp(temp1_map["family_assess_num"]))
		{
		temp1_map = ([]);
		temp1_map["family_assess_num"]=0;
		}

		printf("%|10s��ǰ�Ĺ��׶�Ϊ%d\t���׶Ȼ���Ϊ%d\n",family_name[i],temp_map["job_contribute"],temp1_map["family_assess_num"]);


	}


		return 1;
	

}
int do_check_menpai_job(string arg)
{
	string *option,msg,*member;
	object job_data;
	int wudang,xingxiu,huashan,taohua,gaibang,gumu,emei,baituo,quanzhen,xueshan,dali,shaolin,i;
	if(!arg)
	return notify_fail("��ʽcheck_menpai_job -menpai_name��\n");
	if(!can_used())
		return 0;

	msg="";
	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
			case "-wudang": wudang = 1; break;
			case "-xingxiu": xingxiu = 1; break;
			case "-huashan": huashan = 1; break;
			case "-taohua": taohua = 1; break;
			case "-gumu" : gumu=1;break;
			case "-gaibang": gaibang = 1; break;
			case "-emei": emei = 1; break;
			case "-baituo": baituo = 1; break;
			case "-quanzhen": quanzhen = 1; break;
			case "-xueshan": xueshan = 1; break;
			case "-dali": dali = 1; break;
			case "-shaolin": shaolin = 1; break;

		default:
					return notify_fail("��Ҫ��ʲô����?\n");
		}
	}

		if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
		if(!objectp(job_data)) return 0;
		job_data->restore();
		msg+=copyright;
		if(wudang)
		{
			msg+=job_data->query_family_jobdata("�䵱��");
			member=job_data->choose_of_player("�䵱��","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("�䵱��","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}

		if(xingxiu)
		{
			msg+=job_data->query_family_jobdata("������");
			member=job_data->choose_of_player("������","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("������","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(huashan)
		{
			msg+=job_data->query_family_jobdata("��ɽ��");
			member=job_data->choose_of_player("��ɽ��","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("��ɽ��","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(taohua)
		{
			msg+=job_data->query_family_jobdata("�һ���");
			member=job_data->choose_of_player("�һ���","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("�һ���","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(gaibang)
		{
			msg+=job_data->query_family_jobdata("ؤ��");
			member=job_data->choose_of_player("ؤ��","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("ؤ��","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(emei)
		{
			msg+=job_data->query_family_jobdata("������");
			member=job_data->choose_of_player("������","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("������","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(baituo)
		{
			msg+=job_data->query_family_jobdata("����ɽ");
			member=job_data->choose_of_player("����ɽ","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("����ɽ","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(quanzhen)
		{
			msg+=job_data->query_family_jobdata("ȫ���");
			member=job_data->choose_of_player("ȫ���","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("ȫ���","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(xueshan)
		{
			msg+=job_data->query_family_jobdata("ѩɽ��");
			member=job_data->choose_of_player("ѩɽ��","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("ѩɽ��","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(dali)
		{
			msg+=job_data->query_family_jobdata("����μ�");
			member=job_data->choose_of_player("����μ�","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("����μ�","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(shaolin)
		{
			msg+=job_data->query_family_jobdata("������");
			member=job_data->choose_of_player("������","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("������","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
	
		if(gumu)
		{
			msg+=job_data->query_family_jobdata("��Ĺ��");
			member=job_data->choose_of_player("��Ĺ��","good");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="����������������׶���ߵ���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="������ɹ��׶���ߵ�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("��Ĺ��","bad");
			if(!sizeof(member))
				msg+=HIR"�������û������������ҡ�\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n����������������׶���͵���ң����Ƿֱ��ǣ�\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n������ɹ��׶���͵�����ǣ�\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}

		return 1;

}
int do_start_system()
{
	object job_data,job_system;
	if(!wizardp(this_player()))
			return notify_fail ("�㻹û�л�����ɵķ������޷���������������ϵͳ��\n");
	
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return notify_fail ("���ݿ����������\n");
	job_data->restore();

	if(!find_object(JOB_DIR+"job_system"))
		if(!load_object(JOB_DIR+"job_system"))
			return notify_fail ("job_system�������\n");
		if(job_data->query_job_start())
			return notify_fail ("����������ϵͳ�Ѿ�������\n");

	job_data->set_job_start();
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")������ϵͳ����"+
		" on " 	+ ctime(time()) + "��\n" );
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�����ϵͳ�����ˡ�\n");
	return 1;
}
int do_close_system()
{
	object job_data,job_system;
	if(!wizardp(this_player()))
			return notify_fail ("�㻹û�л�����ɵķ������޷��ر�����������ϵͳ��\n");
	
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return notify_fail ("���ݿ����������\n");
	job_data->restore();

	if(!find_object(JOB_DIR+"job_system"))
		if(!load_object(JOB_DIR+"job_system"))
			return notify_fail ("job_system�������\n");
		if(!job_data->query_job_start())
			return notify_fail ("����������ϵͳ�Ѿ��رա�\n");

	job_data->set_close_start();
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")������ϵͳ�ر�"+
		" on " 	+ ctime(time()) + "��\n" );
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�����ϵͳ�ر��ˡ�\n");
	return 1;
}


int do_cut_job(string arg)
{
	object job_data;
	mapping job_map;
	string player_name,msg;
	msg="";
	if (!can_used())
	return 0;
	if(!arg)
		return notify_fail("job_cut player_name��\n");
	if( sscanf(arg, "%s", player_name)!=1 ) 
		return notify_fail("job_cut player_name��\n");
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");


	job_data->restore();
	if(player_name=="all")
		job_data->reset();
	else
	{
		msg+=copyright;
		msg+="������ɾ��"+arg+"���е�����\n";
		job_map=get_mapping(player_name,"job_player",job_data->query_job_data());
		msg+=(p_map(job_map));
		job_data->detract_job_data(player_name);
	}
	write(msg);
	job_data->save();
	return 1;


}


int do_set_job_contribute(string arg)
{
	object obj_temp;
	string menpai;
	int num;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("��ʽset_contribute menpai_name num��\n");
	if( sscanf(arg, "%s %d", menpai, num)!=2 ) 
		return notify_fail("��ʽset_contribute menpai_name num��\n");
	if(num>100000)
		return notify_fail("����ֵ����ܳ���100000��\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("û��"+menpai+"������ɡ�\n");
	obj_temp->do_set_assess_num(menpai,num);
	obj_temp->save();

	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+menpai+"�Ĺ��׶����ó�" +num+
		" on " 	+ ctime(time()) + "��\n" );
	write(HIY+this_player()->query("name")+"ͻ��˫����ʱ��������ܹ�â��������\n"NOR);
	write("�㽫"+obj_temp->con_name(menpai,2)+"�Ĺ��׶����ó�"+num+"\n");
	//write(HIR"�����������޸ı���Ҫ�ܱ�����Ե�ƽ�⣬�������´��ҡ�\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(menpai,2)+"�Ĺ��׶����ó�"+num+"��\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}


int do_change_rate(string arg)
{
	object obj_temp;
	string menpai;
	int rate;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("��ʽchange_rate menpai_name rate��\n");
	if( sscanf(arg, "%s %d", menpai, rate)!=2 ) 
		return notify_fail("��ʽchange_rate menpai_name rate��\n");
	if(rate>100)
		return notify_fail("����ֵ����ܳ���100��\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("û��"+menpai+"������ɡ�\n");
	obj_temp->do_set_rate(menpai,rate);
	obj_temp->save();

	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+menpai+"��������ֱ������ó�" +rate+
		" on " 	+ ctime(time()) + "��\n" );
	write(HIY+this_player()->query("name")+"ͻ��˫����ʱ��������ܹ�â��������\n"NOR);
	write("�㽫"+obj_temp->con_name(menpai,2)+"��������ּ������ó�"+rate+"\n");
	//write(HIR"�����������޸ı���Ҫ�ܱ�����Ե�ƽ�⣬�������´��ҡ�\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(menpai,2)+"��������ּ������ó�"+rate+"��\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}


int do_check_player(string arg)
{
	object job_data;
	mapping job_map;
	string player_name,msg;
	msg=" ";
	if(!arg)
		return notify_fail("do_check_player player_name��\n");
	if( sscanf(arg, "%s", player_name)!=1 ) 
		return notify_fail("do_check_player player_name��\n");
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");

	job_data->restore();
	job_map=get_mapping(player_name,"job_player",job_data->query_job_data());
	msg+=copyright;
	if(!sizeof(job_map))
	{
		msg+="û�����player����Ϣ��\n";
		write(msg);
		return 1;
	}
	msg+=(p_map(job_map));
	write(msg);

	return 1;
}
int is_online(string name)
{
	if(!find_player(name))
		return 0;
	return 1;
}
int do_check_do_job()
{
	object job_data,*ob;
	mapping job_map;
	string player_name,*ask_job,*oppose_job,*finish_job,msg;
	int i;
	msg="";
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	job_data->restore();
	finish_job=job_data->query_list("finish_job");
	if(pointerp(finish_job))
	finish_job=filter_array(finish_job, (:is_online:));
	ask_job=job_data->query_list("ask_job");
	if(pointerp(ask_job))
	ask_job=filter_array(ask_job, (:is_online:));
	oppose_job=job_data->query_list("oppose_pker");
	if(pointerp(oppose_job))
	oppose_job=filter_array(oppose_job, (:is_online:));	
	msg+=copyright;
	msg+="�����Ѿ��õ����������:\n";

	for(i=0;i<sizeof(ask_job);i++)
		msg+=ask_job[i]+"\n";
	msg+="��������ִ�����������:\n";
	
	for(i=0;i<sizeof(oppose_job);i++)
		msg+=oppose_job[i]+"\n";
	msg+="�����Ѿ�������������:\n";

	for(i=0;i<sizeof(finish_job);i++)
		msg+=finish_job[i]+"\n";
	write(msg);
	return 1;

}
int do_start(string arg)
{
	object obj_temp;
	string player_name;
	if (!can_used())
	return 0;
/*	if(query("job_start"))
		return notify_fail ("���ֻþ�����ϵͳ�Ѿ��������ˡ�\n");


	write(HIY+this_player()->query("name")+"��Ŀ����˫���ѹ�����̬�仯�����������д�......��\n"NOR);
	write(HIY+this_player()->query("name")+"ͻ�Ĵ��һ������������\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�ͻȻ�����ɫ����������������һ����⻮����ʣ�ɲ�Ǽ��ָֻ�ƽ��......");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ����ֻþ�����ϵͳ������\n");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")�����ֻþ�����ϵͳ����" +
		" on " 	+ ctime(time()) + "��\n" );
	set("job_start",1);
	*/
	if(!arg)
	{
		if(!(obj_temp=find_object("/clone/obj/job/job_produce")))
			if(!obj_temp=new("/clone/obj/job/job_produce"))
				return notify_fail("/clone/obj/job/job_produce.c��ʼ������\n");
			obj_temp->restore();
			obj_temp->produce_job(0);
			return 1;

	}

	if( sscanf(arg, "%s", player_name)!=1 ) 
		return notify_fail("��ʽjob_start player_name��\n");

	if(!(obj_temp=find_object("/clone/obj/job/job_produce")))
		if(!obj_temp=new("/clone/obj/job/job_produce"))
			return notify_fail("/clone/obj/job/job_produce.c��ʼ������\n");
		obj_temp->restore();
		if(!find_player(player_name))
			return notify_fail("û�������ҡ�\n");
		obj_temp->produce_job(player_name);
	return 1;
}


/*
int do_setorg_pwoer(string arg)
{
	object obj_temp;
	string menpai,area;
	int num;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("��ʽset_orgpwoer menpai_name area area_num��\n");
	if( sscanf(arg, "%s %s %d", menpai, area,num)!=3 ) 
		return notify_fail("��ʽset_orgpwoer menpai_name area area_num��\n");
	if(num>100)
		return notify_fail("����ֵ����ܳ���100��\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("û��"+menpai+"������ɡ�\n");
	if(!obj_temp->have_power(menpai,area,num))
	return notify_fail("û��"+area+"�������\n");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+menpai+"��"+area+"���������ó�" +num+
		" on " 	+ ctime(time()) + "��\n" );
	write(HIY+this_player()->query("name")+"ͻ��˫����ʱ��������ܹ�â��������\n"NOR);
	write("�㽫"+obj_temp->con_name(menpai,2)+"��"+area+"���������ó�"+num+"\n");
	write(HIR"�����������޸ı���Ҫ�ܱ�����Ե�ƽ�⣬�������´��ҡ�\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(menpai,2)+"��"+area+"���������ó�"+num+"��\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}

int do_setorg_strategy(string arg)
{
	object obj_temp;
	string menpai,strategy;
	int num;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("��ʽset_orgstrategy menpai_name strategy strategy_num��\n");
	if( sscanf(arg, "%s %s %d", menpai, strategy,num)!=3 ) 
		return notify_fail("��ʽset_orgstrategy menpai_name strategy strategy_num��\n");
	if(num>100)
		return notify_fail("����ֵ����ܳ���100��\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("û��"+menpai+"������ɡ�\n");
	if(!obj_temp->have_strategy(menpai,strategy,num))
	return notify_fail("û��"+strategy+"������ԡ�\n");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+menpai+"��"+strategy+"������ֵ���ó�" +num+
		" on " 	+ ctime(time()) + "��\n" );
	write(HIY+this_player()->query("name")+"ͻ��˫����ʱ��������ܹ�â��������\n"NOR);
	write("�㽫"+obj_temp->con_name(menpai,2)+"��"+strategy+"������ֵ���ó�"+num+"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(menpai,2)+"��"+strategy+"������ֵ���ó�"+num+"��\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}
int do_setorg_luck(string arg)
{
	object obj_temp;
	string menpai;
	int num;
	if (!can_used())
	return 0;
	if(!arg)
		return notify_fail("��ʽset_orgluck menpai_name luck_num��\n");
	if( sscanf(arg, "%s %d", menpai, num)!=2 ) 
		return notify_fail("��ʽset_orgluck menpai_name luck_num��\n");
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
		return notify_fail("û��"+menpai+"������ɡ�\n");
	if(num>10)
		return notify_fail("����ֵ���Ϊ10��\n");
	obj_temp->do_set_luck(menpai,num);
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+menpai+"������ָ�����ó�" +num+
		" on " 	+ ctime(time()) + "��\n" );
	write(HIY+this_player()->query("name")+"ͻ��˫����ʱ��������ܹ�â��������\n"NOR);
	write("�㽫"+obj_temp->con_name(menpai,2)+"������ָ���ĳ�"+num+"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(menpai,2)+"������ָ�����ó�"+num+"��\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}

int do_setorg_money(string arg)
{
	object obj_temp;
	string menpai;
	int num;
	if (!can_used())
	return 0;
	if(!arg)
		return notify_fail("��ʽset_orgmoney menpai_name money_num��\n");
	if( sscanf(arg, "%s %d", menpai, num)!=2 ) 
		return notify_fail("��ʽset_orgmoney menpai_name money_num��\n");
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
		return notify_fail("û��"+menpai+"������ɡ�\n");

	obj_temp->do_set_money(menpai,num);
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+menpai+"�Ľ�Ǯϵ�����ó�" +num+
		" on " 	+ ctime(time()) + "��\n" );
	write(HIY+this_player()->query("name")+"ͻ��˫����ʱ��������ܹ�â��������\n"NOR);
	write("�㽫"+obj_temp->con_name(menpai,2)+"�Ľ�Ǯϵ���ĳ�"+num+"\n");
	write(HIY"��Ǯϵ�����޸ı���Ҫ�ܱ��ֺ��������ɵ���Ե�ƽ�⣬�������¾��ñ�����\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ�΢΢�������ƺ�Ԥʾ��ʲô������");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(menpai,2)+"�Ľ�Ǯϵ�����ó�"+num+"��\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}


int do_setorg_default(string arg)
{
	object obj_temp;
	string menpai;
		if (!can_used())
		return 0;
	if (!arg) 
		return notify_fail("job_setorg_default allȫ�����ɳ�ʼ�����á�\n"
		"job_setorg_default menpai_nameָ�����ɳ�ʼ�����á�\n");

	if( sscanf(arg, "%s", menpai)!=1 ) 
		return notify_fail("job_setorg_default allȫ�����ɳ�ʼ�����á�\n"
		"job_setorg_default menpai_nameָ�����ɳ�ʼ�����á�\n");

	
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	
	obj_temp->restore();
	if(arg=="all")
	{
	obj_temp->set_default();
	obj_temp->add_orgdata("�䵱��",strategy_wd,luck_wd,money_wd,luck_wdrate,power_wd,assess_wd);
	obj_temp->add_orgdata("������",strategy_xx,luck_xx,money_xx,luck_xxrate,power_xx,assess_xx);
	obj_temp->add_orgdata("��ɽ��",strategy_hs,luck_hs,money_hs,luck_hsrate,power_hs,assess_hs);
	obj_temp->add_orgdata("�һ���",strategy_th,luck_th,money_th,luck_thrate,power_th,assess_th);
	obj_temp->add_orgdata("ؤ��",strategy_gb,luck_gb,money_gb,luck_gbrate,power_gb,assess_gb);
	obj_temp->add_orgdata("������",strategy_em,luck_em,money_em,luck_emrate,power_em,assess_em);
	obj_temp->add_orgdata("����ɽ",strategy_bt,luck_bt,money_bt,luck_btrate,power_bt,assess_bt);
	obj_temp->add_orgdata("ȫ���",strategy_qz,luck_qz,money_qz,luck_qzrate,power_qz,assess_qz);
	obj_temp->add_orgdata("ѩɽ��",strategy_xs,luck_xs,money_xs,luck_xsrate,power_xs,assess_xs);
	obj_temp->add_orgdata("����μ�",strategy_dl,luck_dl,money_dl,luck_dlrate,power_dl,assess_dl);
	obj_temp->add_orgdata("������",strategy_sl,luck_sl,money_sl,luck_slrate,power_sl,assess_sl);
	obj_temp->add_orgdata("��Ĺ��",strategy_gm,luck_gm,money_gm,luck_slrate,power_gm,assess_gm);

	write("�㽫���ֻþ��ĸ����ɲ�������Ϊȴʡ��ֵ��\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ䷢��һ˿˿�������ƺ�Ԥʾ��ʲô�����");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ������ɵ�ϵͳ�������ó�ȴʡֵ��");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")�������ɵ�ϵͳ�������ó�ȴʡֵ" +
		" on " 	+ ctime(time()) + "��\n" );
	return 1;
	}

	switch(arg) {
		case "wudang":
			obj_temp->change_orgdata("�䵱��",strategy_wd,luck_wd,money_wd,power_wd);
			break;
		case "xingxiu":
			obj_temp->change_orgdata("������",strategy_wd,luck_wd,money_wd,power_wd);
			break;

			default:
				return notify_fail("Ŀǰ���ֻþ�����ϵͳ��֧��"+arg+"����\n");
		}
	write(HIW+this_player()->query("name")+"�ۼ�����˫�ֺϳ�һ��Բ�����һ����߾������\n"NOR);
	
	CHANNEL_D->do_channel(this_object(), "rumor", "��ؼ䷢��΢΢�������ƺ�Ԥʾ��ʲô�����");
	CHANNEL_D->do_channel(this_player(), "sys", "�ҽ�"+obj_temp->con_name(arg,2)+"��ϵͳ�������ó�ȴʡֵ��");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")��"+obj_temp->con_name(arg,2)+"��ϵͳ�������ó�ȴʡֵ" +
		" on " 	+ ctime(time()) + "��\n" );


	obj_temp->save();
	if(obj_temp)
	destruct(obj_temp);


	return 1;
//int add_orgdata(string family_name,mapping strategy,int luck,int money,mapping power)


}
*/

/*
int do_check(string arg)
{
	object me,obj_temp;
	string *option,help_message;
	int i,menpai,help,luck,money,strategy,wudang,xingxiu,huashan,taohua,gaibang,emei,baituo,
		quanzhen,xueshan,dali,shaolin,rate,gumu;
	me=this_player();
	
	if (!arg) 
		return notify_fail("��Ҫ��ʲô�����Ҫ���job_check����������job_check -help \n");
	//��ѯ���ɵ������Ϣ

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
			case "-menpai": menpai = 1; break;
			case "-help": help = 1; break;
			case "-luck": luck = 1; break;
			case "-money": money = 1; break;
			case "-strategy": strategy = 1; break;
			case "-wudang": wudang = 1; break;
			case "-xingxiu": xingxiu = 1; break;
			case "-huashan": huashan = 1; break;
			case "-taohua": taohua = 1; break;
			case "-gaibang": gaibang = 1; break;
			case "-emei": emei = 1; break;
			case "-baituo": baituo = 1; break;
			case "-quanzhen": quanzhen = 1; break;
			case "-xueshan": xueshan = 1; break;
			case "-dali": dali = 1; break;
			case "-shaolin": shaolin = 1; break;
			case "-gumu": gumu = 1; break;
			case "-rate": rate=1;break;
		default:
					return notify_fail("��Ҫ��ʲô�����Ҫ���job_check����������job_check -help \n");
		}
	}
	if(help)
	{
		
		write(copyright);
		help_message = "-menpai\t\t������������Ϣ��\n" ;
		help_message += "-luck\t\t�������������ֵ�б�\n" ;
		help_message += "-money\t\t������ɽ�Ǯϵ���б�\n" ;
		//help_message += "-strategy\t������ɲ���һ���б�\n" ;
		help_message += "-menpai_name\t���������ȫ��ϸ�б�\n" ;
		help_message += "-rate\t�����������������ʡ�\n" ;
		me->start_more(help_message);
		return 1;



	}
	write(copyright);
	if(wudang)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("wudang"))
		return notify_fail("û��"+"wudang"+"������ɡ�\n");


	obj_temp->query_full_menpaidata("wudang");
	}
	if(xingxiu)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("xingxiu"))
		return notify_fail("û��"+"xingxiu"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("xingxiu");
	}

	if(huashan)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("huashan"))
		return notify_fail("û��"+"huashan"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("huashan");
	}
	if(taohua)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("taohua"))
		return notify_fail("û��"+"taohua"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("taohua");
	}
	if(gaibang)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("gaibang"))
		return notify_fail("û��"+"gaibang"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("gaibang");
	}
	if(emei)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("emei"))
		return notify_fail("û��"+"emei"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("emei");
	}
	if(baituo)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("baituo"))
		return notify_fail("û��"+"baituo"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("baituo");
	}
	if(quanzhen)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("quanzhen"))
		return notify_fail("û��"+"quanzhen"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("quanzhen");
	}
	if(xueshan)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("xueshan"))
		return notify_fail("û��"+"xueshan"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("xueshan");
	}
	if(dali)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("dali"))
		return notify_fail("û��"+"dali"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("dali");
	}
	if(shaolin)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("shaolin"))
		return notify_fail("û��"+"shaolin"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("shaolin");
	}
	if(gumu)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");
	if(!obj_temp->have_menpai("gumu"))
		return notify_fail("û��"+"gumu"+"������ɡ�\n");
	obj_temp->query_full_menpaidata("gumu");
	}

	if(luck)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");

	obj_temp->query_luck_list();
	}
	if(money)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");

	obj_temp->query_money_list();
	}
	if(menpai)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");

	obj_temp->query_menpai_list();
	}
	if(rate)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai��ʼ������\n");
	if(!obj_temp->restore())
		return notify_fail("��ʼ��job_menpai�������������á�\n");

	obj_temp->query_rate_list();
	}
	if(obj_temp)
	destruct(obj_temp);
	
	
	return 1;

}
*/
