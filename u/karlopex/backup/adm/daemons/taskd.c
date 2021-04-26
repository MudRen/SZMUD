//last modified by buwu

inherit F_DBASE;

#include <ansi.h>
#define MAX_TIMES 20

private static mapping task_list=([]);
private static object *task_ob=({});
private static mapping ok_dir=([
	"/d/baituo/"   : "�������ɽ",
	"/d/changbai/" : "���ⳤ��ɽ",
	"/d/city/"     : "����",
	"/d/dali/"     : "���ϴ���",
	"/d/emei/"     : "�Ĵ�����",
	"/d/forest/"   : "���ݽ���",
	"/d/foshan/"   : "�㶫��ɽ",
	"/d/gaibang/"  : "ؤ�����ڵ�",
	"/d/hangzhou/" : "����",
	"/d/huanghe/"  : "�ƺӱ�",
	"/d/huashan/"  : "��ɽ",
	"/d/jiaxing/"  : "����",
	"/d/qilian/"   : "����ɽ",
	"/d/quanzhou/" : "����Ȫ��",
	"/d/shaolin/"  : "��ɽ����",
	"/d/taihu/"    : "̫����",
	"/d/taishan/"  : "ɽ��̩ɽ",
	"/d/taohua/"   : "�����һ���",
	"/d/wudang/"   : "�����䵱ɽ",
	"/d/xingxiu/"  : "����",
	"/d/xixia/"    : "����",
	"/d/xueshan/"  : "�رߴ�ѩɽ",
	"/d/zhongnan/" : "����ɽ",
        "/d/gumu/"     : "��Ĺ",
        ]);

void update_task();
void ready_update_task();
object random_place();
object random_npc(object);
int move_to(object,object);
string query_task_list();
void task_done(string);
int task_give(object,object,object);
object do_clone(object,object);
void give_reward(object,object);
mixed query_location(string);
void pre_destruct();

void create()
{
	seteuid(getuid());
        set("channel_id",HIW"����ͬ������(ShenZhou)"NOR);
	ready_update_task();
}

void pre_destruct()
{
	for(int j=0;j<sizeof(task_ob);j++)
	{
		if(!undefinedp(task_ob[j])&&objectp(task_ob[j]))
		destruct(task_ob[j]);
	}
	task_ob=({});
}

void ready_update_task()
{
	CHANNEL_D->do_channel(this_object(),"chat",HIG"ʮ��ĥһ����˪��δ���ԡ����հѾ��ʣ�˭�в�ƽ�¡�\n"NOR);
	CHANNEL_D->do_channel(this_object(),"chat",HIG"���λӢ��������Ϣ��Ԥ���÷�Σ�������ε���ȭ��\n"NOR);
	remove_call_out("update_task");
	call_out("update_task",180);
}

void update_task()
{
	string file,*task=({}),file2,npc_s,room_s,*npc_list=({}),*key,err;
	mapping tmp=([]);
	object ob,where,room;
	task_list=([]);
	for(int j=0;j<sizeof(task_ob);j++)
	{
		if(!undefinedp(task_ob[j])&&objectp(task_ob[j]))
		destruct(task_ob[j]);
	}
	task_ob=({});
	if(!file=read_file("/task/task_list")) return;
	if(!file2=read_file("/task/npc_list")) return;
	task=explode(file,"\n");
	npc_list=explode(file2,"\n");
	for(int j=0;j<sizeof(npc_list);j++)
	{
		
		if(sscanf(npc_list[j],"%s:%s",npc_s,room_s)!=2) continue;
		tmp[npc_s]=room_s;
	}
	key=keys(tmp);
	
	for(int i=0;i<sizeof(task);i++)
	{
		int num;
		object npc;
		reset_eval_cost();
		err=catch(ob=new(task[i]));
		if(err) {
			log_file("task_obj","cannt new ob:"+task[i]+"\n");
			continue;
		}
		for(int kk=0;kk<10;kk++)
		{
		where=random_place();
		if(where==this_object()) continue;
		if((num=member_array(ob->query("task_owner"),key))!=-1)	
		{
		
			if(!objectp(room=load_object(tmp[key[num]]))) continue;
			if(!objectp(npc=present(key[num],room))) continue;
	//		log_file("task_obj",npc->name()+ob->name()+num+key[num]+tmp[key[num]]+"\n");
                    npc->set("task_ob",ob->query("id"));
//                    npc->set("task_object",1);
                    ob->set("task_object",1);
		}
		
		if(!move_to(ob,where)) {log_file("task_obj","cannt move"+ob->name()+"to "+base_name(where)+"\n");continue;}
		task_list[npc->name()+"��"+ob->query("name")]=HIY"(�������)"NOR;
		task_ob+=({ob});
		break;
		}
	}
	CHANNEL_D->do_channel(this_object(),"chat",HIY"�ã�������Թ(quest)������ϣ����λ����Ӣ�۳����ɣ�\n"NOR);
	remove_call_out("ready_update_task");
        call_out("ready_update_task",1800);
}

object random_place()
{
	string main_dir,*place=({}),*dir,filename,*dirs,err;
	object output;
	int num,tmp;
	dirs=keys(ok_dir);
	main_dir=dirs[random(sizeof(dirs))];
	//log_file("task",main_dir+"\n");
	dir=get_dir(main_dir);
	for(int i=0;i<sizeof(dir);i++)
	{
		if(file_size(main_dir+dir[i])<=0||sscanf(dir[i],"%s.c",filename)!=1)
		continue;
		place+=({dir[i]});
	//	log_file("task",dir[i]+"\n");
	}
	num=sizeof(place);
	//log_file("task",num+"\n");
	while(num--)
	{
		tmp=random(sizeof(place));
		err=catch(call_other(main_dir+place[tmp],"??"));
		if(err)
		{
	//		log_file("task",place[tmp]+"is not load\n");
			continue;
		}
		else
		{
			if(!(output=load_object(main_dir+place[tmp]))) continue;
			output->set("main_dir",main_dir);
			return output;
		}
		
	}
//	log_file("task","cannt find correct where\n");
	return this_object();
}

int move_to(object source,object target)
{
	object *inv,*ls=({});
	mapping ob;
	string *key;
	if(!objectp(source)||!objectp(target)) return 0;
	inv=all_inventory(target);
	ob=target->query("objects");
	if(sizeof(ob)>0)
	{
		key=keys(ob);
		for(int i=0;i<sizeof(inv);i++)
		{
			if(member_array(base_name(inv[i]),key)!=-1||
			member_array(base_name(inv[i])+".c",key)!=-1)
			if(living(inv[i])&&
                                function_exists("die",inv[i])=="/feature/damage")
			ls+=({inv[i]});
		}
	}
	if(sizeof(ls)<=0) return 0;
	if(source->move(ls[random(sizeof(ls))]))
	return 1;
	else return 0;
}

string query_task_list()
{
	string output="",*key;
	key=keys(task_list);
	for(int i=0;i<sizeof(key);i++)
	{
		output+=sprintf("	%-25s%s\n",key[i],task_list[key[i]]);
	}
	return output;
}

void task_done(object ob)
{
	string *key;
	int num;
	key=keys(task_list);
	if(num=member_array(ob->query("task_owner_cname")+"��"+ob->query("name"),key)!=-1
	&&member_array(ob,task_ob)!=-1) 
	{
		string index=ob->query("task_owner_cname")+"��"+ob->query("name");
		task_list[index]=HIR"(��Թ�˽�)"NOR;
		task_ob-=({ob});
	}
	
	return;
}

int task_give(object me,object who,object ob)
{
	object target,where;
	string tmp;
	int timer=0;
	if(ob->query("task_owner")==who->query("id")&&userp(me)
	&&task_list[ob->query("task_owner_cname")+"��"+ob->query("name")]!=HIR"(��Թ�˽�)"NOR)
	{
	task_done(ob);
	who->delete("task_ob");
	who->delete("no_clean_up");
	give_reward(me,ob);
	destruct(ob);
	who->command("smile");
	me->add_temp("get_taskob",1);
	if(me->query_temp("get_taskob")>9) me->set_temp("get_taskob",4);
	target=random_npc(me);
	message("vision",CYN+who->name()+"˵����"+RANK_D->query_self(who)+"��׷�鵽���ߴ������"+
    	target->name()+"("+target->query("id")+")��\n"+RANK_D->query_respect(me)
    	+"���ܽ�����ɱ������Ϊ������ȥһ����Ҳ��Ϊ"+RANK_D->query_self(who)+
    	"�ָ��������Ե��м�������\n"+NOR,me);
	where=this_object();
	while(where==this_object()&&++timer<10)
	{
		where=random_place();
	}
	if(!objectp(where))
	{
		message("vision","�����ܾ�û����˵�����������ˡ�\n",me);
		return 1;
	}
	//write(where->query("main_dir")+"\n"+ok_dir[where->query("main_dir")]+"\n"+
//	base_name(where)+"\n");
	tmp=ok_dir[where->query("main_dir")];
	message("vision",CYN+who->name()+"˵����������Ž������Դ�������"+tmp+"������û����֪��Ϣ�Ƿ���š�\n"+NOR,me);
	target->set("task_bekill",me->query("id"));
	target->set("wait_time",900-50*random(me->query_temp("task_level")));
	target->set("task_level",me->query_temp("task_level"));
	me->set_temp("task_target",target->query("id"));
	target->goto_leave();
	target->move(where);
	return 1;
	}
	return 0;
	
}
	
object random_npc(object me)
{
	object output;
	string nickname,name,*tmp,*pinying;
	mapping skill;
	name=NAME_D->create_name();
	nickname=NAME_D->create_nick();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	output=new("/task/npc/target");
	output->set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	output->set("nickname",nickname);
	output->set("gender",random(3)>0?"����":"Ů��");//male sadan is more..:)
	output=do_clone(output,me);
	return output;
}

object do_clone(object output,object me)
{
    object *inv, newob;
    mapping hp_status, skill_status, map_status, prepare_status;
    string *sname, *mname, *pname;
    int i, temp,lvl,lvlx,lvlxx,level,exp,exp_reward,pot_reward;

    seteuid( geteuid(output) );
    lvl=me->query_temp("task_level");
      
        exp=me->query("combat_exp");
	if (exp < 750000){ 
		lvlx = 85 + random(5); 
		lvlxx = 85 + random(5);
	}else{
		lvlx = 80 + random(5);
		lvlxx = 90 + random(5);
		}
/* copy entire dbase values */


    hp_status = me->query_entire_dbase();


        output->set("str", hp_status["str"]);
        output->set("int", hp_status["int"]);
        output->set("con", hp_status["con"]);
	output->set("dex", hp_status["dex"]);
        output->set("age", hp_status["age"]);


        output->set("max_qi",    hp_status["max_qi"]*(lvl+1)/3);
        output->set("eff_qi",    output->query("max_qi"));
        output->set("qi",        output->query("max_qi"));
        output->set("max_jing",  hp_status["max_jing"]*(lvl+1)/3);
        output->set("eff_jing",  output->query("max_jing"));
        output->set("jing",      output->query("max_jing"));
        output->set("max_neili", hp_status["max_neili"]*(lvl+1)/3);
        output->set("neili",     output->query("max_neili"));
        output->set("max_jingli",hp_status["max_jingli"]*(lvl+1)/3);
        output->set("jingli",    output->query("max_jingli"));
        output->set("jiali",     to_int(sqrt(to_float(output->query("max_neili")))));
        output->set("gender",    hp_status["gender"]);
        output->set("combat_exp",hp_status["combat_exp"] * lvlx / 100);
        

	level = pow(10*output->query("combat_exp"), 0.333334);
	if (level < 20) level = 20;

	    output->set_skill("force", level);
	    output->set_skill("dodge", level * lvlxx / 100);
	    output->set_skill("parry", level * lvlxx / 100);
	    output->set_skill("sword", level);
	    output->set_skill("blade", level);
	    output->set_skill("strike", level);
	    output->set_skill("cuff", level);
	    output->set_skill("finger", level);
	    output->set_skill("claw", level);
	    output->set_skill("club", level);
	    output->set_skill("kick", level);
	    output->set_skill("staff", level);
	    output->set_skill("whip", level);
	    switch (random(8)){
	    case 0:
	        output->set_skill("huashan-jianfa", level);
	        output->set_skill("liangyi-dao", level);
	        output->set_skill("huashan-shenfa", level);
	        output->set_skill("zixia-gong", level);
		output->set_skill("pishi-poyu", level);
		output->set_skill("hunyuan-zhang", level);
	 
	        output->map_skill("force", "zixia-gong");
	        output->map_skill("dodge", "huashan-shenfa");
	        output->map_skill("parry", "huashan-jianfa");
	        output->map_skill("strike", "hunyuan-zhang");
		output->map_skill("cuff", "pishi-poyu");
	        output->map_skill("sword", "huashan-jianfa");
	        output->map_skill("blade", "liangyi-dao");
	        
	        output->prepare_skill("cuff", "pishi-poyu");
	        output->prepare_skill("strike", "hunyuan-zhang");
		
		output->set("default_weapon", "/clone/weapon/gangjian");
		break;
	
	    case 1:
		output->set_skill("huifeng-jian", level);
		output->set_skill("yanxing-dao", level);
		output->set_skill("jinding-zhang", level);
		output->set_skill("tiangang-zhi", level);
		output->set_skill("linji-zhuang", level);
		output->set_skill("zhutian-bu", level);
	
		output->map_skill("force", "linji-zhuang");
		output->map_skill("sword", "huifeng-jian");
		output->map_skill("blade", "yanxing-dao");
		output->map_skill("strike", "jinding-zhang");
		output->map_skill("finger", "tiangang-zhi");
		output->map_skill("dodge", "zhutian-bu");
		output->map_skill("parry", "huifeng-jian");
	
	        output->prepare_skill("finger", "tiangang-zhi");
	        output->prepare_skill("strike", "jinding-zhang");
		output->set("default_weapon", "/clone/weapon/gangdao");
		break;
	
	    case 2:
	        output->set_skill("taiji-shengong", level);
	        output->set_skill("taiji-jian", level);
	        output->set_skill("tiyunzong", level);
		output->set_skill("taiji-quan", level);
	 
	        output->map_skill("force", "taiji-shengong");
	        output->map_skill("parry", "taiji-jian");
		output->map_skill("cuff", "taiji-quan");
	        output->map_skill("dodge", "tiyunzong");
	        output->map_skill("sword", "taiji-jian");
	        
	        output->prepare_skill("cuff", "taiji-quan");
		output->set("default_weapon", "/clone/weapon/gangjian");
	        output->set("chat_chance_combat", 50);
		break;
	
	    case 3:
	        output->set_skill("damo-jian", level);
	        output->set_skill("xiuluo-dao", level);
	        output->set_skill("wuchang-zhang", level);
	        output->set_skill("zui-gun", level);
	        output->set_skill("shaolin-shenfa", level);
	        output->set_skill("hunyuan-yiqi", level);
		output->set_skill("yizhi-chan", level);
		output->set_skill("banruo-zhang", level);
	 
	        output->map_skill("force", "hunyuan-yiqi");
	        output->map_skill("dodge", "shaolin-shenfa");
	        output->map_skill("parry", "damo-jian");
	        output->map_skill("sword", "damo-jian");
	        output->map_skill("blade", "xiuluo-dao");
	        output->map_skill("club", "zui-gun");
	        output->map_skill("staff", "wuchang-zhang");
	        output->map_skill("finger", "yizhi-chan");
	        output->map_skill("strike", "banruo-zhang");
	        
	        output->prepare_skill("finger", "yizhi-chan");
	        output->prepare_skill("strike", "banruo-zhang");
		output->set("default_weapon", "/clone/weapon/gangjian");
		break;
	
	    case 4:
	        output->set_skill("liuhe-dao", level);
	        output->set_skill("xiaoyaoyou", level);
	        output->set_skill("huntian-qigong", level);
		output->set_skill("shexing-diaoshou", level);
	 
	        output->map_skill("force", "huntian-qigong");
	        output->map_skill("dodge", "xiaoyaoyou");
	        output->map_skill("parry", "liuhe-dao");
	        output->map_skill("blade", "liuhe-dao");
	        output->map_skill("hand", "shexing-diaoshou");
	        
	        output->prepare_skill("hand", "shexing-diaoshou");
		output->set("default_weapon", "/clone/weapon/gangdao");
		break;
	
	    case 5:
	        output->set_skill("hamagong", level);
	        output->set_skill("lingshe-zhang", level);
		output->set_skill("chanchubu", level);
		output->set_skill("poison", level);
	 
	        output->map_skill("force", "hamagong");
	        output->map_skill("dodge", "chanchubu");
	        output->map_skill("parry", "lingshe-zhang");
	        output->map_skill("strike", "hamagong");
	        output->map_skill("staff", "lingshe-zhang");
	        
	        output->prepare_skill("strike", "hamagong");
		output->set("default_weapon", "/clone/weapon/shezhang");
		break;
	
	    case 6:
	        output->set_skill("bitao-xuangong", level);
	        output->set_skill("canglang-bian", level);
	        output->set_skill("luoying-shenfa", level);
		output->set_skill("luoying-shenjian", level);
		output->set_skill("xuanfeng-saoye", level);
		output->set_skill("qimen-dunjia", level);
	 
	        output->map_skill("force", "bitao-xuangong");
	        output->map_skill("dodge", "luoying-shenfa");
	        output->map_skill("parry", "canglang-bian");
	        output->map_skill("strike", "luoying-shenjian");
	        output->map_skill("kick", "xuanfeng-saoye");
	        output->map_skill("whip", "canglang-bian");
	        
	        output->prepare_skill("strike", "luoying-shenjian");
	        output->prepare_skill("kick", "xuanfeng-saoye");
		output->set("default_weapon", "/clone/weapon/changbian");
		break;
	
	    case 7:
	        output->set_skill("longxiang-banruo", level);
	        output->set_skill("xue-dao", level);
	        output->set_skill("jingang-chu", level);
		output->set_skill("huoyan-dao", level);
		output->set_skill("xueshitiao", level);
		output->set_skill("mingwang-jian", level);
	 
	        output->map_skill("force", "longxiang-banruo");
	        output->map_skill("dodge", "xueshitiao");
	        output->map_skill("parry", "xue-dao");
	        output->map_skill("blade", "xue-dao");
	        output->map_skill("sword", "mingwang-jian");
	        output->map_skill("strike", "huoyan-dao");
	        output->map_skill("staff", "jingang-chu");
	        
	        output->prepare_skill("strike", "huoyan-dao");
		output->set("default_weapon", "/clone/weapon/gangdao");
		break;
	
	    case 8:
	    default:
	        output->set_skill("huagong-dafa", level);
	        output->set_skill("zhaixinggong", level);
	        output->set_skill("chousui-zhang", level);
	        output->set_skill("sanyin-zhua", level);
	        output->set_skill("tianshan-zhang", level);
	        output->set_skill("poison", level);
	
		output->map_skill("force", "huagong-dafa");
		output->map_skill("strike", "chousui-zhang");
		output->map_skill("claw", "sanyin-zhua");
		output->map_skill("dodge", "zhaixinggong");
		output->map_skill("parry", "sanyin-zhua");
		output->map_skill("staff", "tianshan-zhang");
	
		output->prepare_skill("strike", "chousui-zhang");
		output->prepare_skill("claw", "sanyin-zhua");
		output->set("default_weapon", "/clone/weapon/gangzhang");
		break;
	    }

	if(exp<30000) {
	    exp_reward=300+exp/400;
	    pot_reward=20+exp/1200;
	} else if(exp<300000) {
	    exp_reward=600+exp/800;
	    pot_reward=40+exp/12000;
	    
	} else if(exp<3000000) {
	    exp_reward=1200+exp/6000;
	    pot_reward=80+exp/120000;
	    
	} else {
	    exp_reward=3000+random(500);
	    pot_reward=100+random(50);
	    
	}
	pot_reward=pot_reward*(lvl+1)/6;
	exp_reward=exp_reward*(lvl+1)/6;
	output->set("kill_reward/pot",pot_reward);
	output->set("kill_reward/exp",exp_reward);
	return output;
}

void give_reward(object me,object ob)
{
	int exp_r,pot_r,rpoint;
	rpoint=ob->query("reward_point");
	//exp_r=123*(rpoint+1)*(me->query_temp("get_taskob")+1)/6;
	exp_r=400+random(200);
	//pot_r=63*(rpoint+1)*(me->query_temp("get_taskob")+1)/6;
	pot_r=100+random(150);
	me->add("combat_exp",exp_r);
	me->add("potential",pot_r);
	if( ob->query("potential") > ob->query("max_potential") ) 
	ob->set("potential",ob->query("max_potential") );
       	log_file("quest_new",sprintf("%s(%s) get %d exp and %d pot from task job on %s. \n",
			me->name(), getuid(me), exp_r, pot_r, ctime(time())));
	message("vision","�㱻������"+chinese_number(exp_r)+"�㾭���"+
	chinese_number(pot_r)+"��Ǳ�ܣ�\n",me);
	return;
}

mixed query_location(string arg)
{
	string *biaodian=({
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
	});
	
	string *key,*owner,*name,ow,na,des,*ch=({});
	string output=arg+"��һ������";
	object ob,where;
	mapping exits;
	int tmp;
	key=keys(task_list);
	if(member_array(arg,key)!=-1&&task_list[arg]!=HIR"(��Թ�˽�)"NOR)
	{
		int flag=0,index;
		for(int i=0;i<sizeof(task_ob);i++)
		{
                        if(undefinedp(task_ob[i])||!objectp(task_ob[i])) continue;
			if(arg==task_ob[i]->query("task_owner_cname")+"��"+
			task_ob[i]->query("name")) 
			{
				index=i;
				flag=1;
				break;
			}
			
			
		}
		if(flag)
		{
			ob=task_ob[index];
			where=ob;
			while(1)
			{
				where=environment(where);
				if(!where) return -1;
				if(!where->is_character()&&!clonep(where)) break;
			}
			
			exits=where->query("exits");
			if(sizeof(exits)>0)
			{
				key=keys(exits);
				for(int i=0;i<sizeof(key);i++)
				{
					output+=HIY+key[i]+NOR+(i==(sizeof(key)-1)?"":",");
				}
				output+="�ĳ��ڵĵط���\n";
			}
			else
			{
				output=arg+"��һ��û�г��ڵĵط���\n";
			}
			des=where->query("long");
			if(sizeof(des)==0) return output;
			for(int i=0;i<sizeof(des);i++)
			{
				if(des[i]>160&&des[i]<255)
				{
					if(member_array(des[i..i+1],biaodian)==-1)
					{
						ch+=({des[i..i+1]});
					}
					i++;
					
				}
				
			}
			if(sizeof(ch)==0) return output;
			if(sizeof(ch)==1) {
				output+="����ط�������ֻ��һ���֣�"+ch[0]+"\n";
				return output;
			}
			
			tmp=random(sizeof(ch));
			if(tmp+1==sizeof(ch)) tmp=0;
			output+="����ط��������к������������ۣ�"+ch[tmp]+ch[tmp+1];
			tmp+=random(5)+1;
			if(tmp>=sizeof(ch)-1) tmp=0;
			output+=","+ch[tmp]+ch[tmp+1]+"\n";
			return output;
		}
		
		return -2;
	}
}

			
			
			
			
			
			
		





