// �����ݡ���
// Yujie Sep 30
// topten_add,topten_del,topten_query from jackboy's topten

#include <ansi.h>
#include <mudlib.h>

#define CHINESE_MUD_NAME "�����ݡ�"

inherit F_DBASE;

int create_top_file(string top_id);
int create_ban_file(string top_id);
string query_top_file(string top_id);
string query_ban_file(string top_id);
int is_banned(string, object);
int do_ban(string, string, int);
int add_top(string top_id, string name, string prop);
string query_top(string top_id, int op);
int delete_top(string top_id);
int topten_add(object player,string type);
int topten_del(string pid,string type);
int get_all_data(object player,string top_id);
string topten_query(string type);
void topten_checkplayer(object player);

void create()
{
	seteuid(geteuid());	
        set("name", "���а���");
	set("id", "topd");
}

mapping min_limit = ([ // one must own a bigger value than the bellow if he enters topten. 
	"exp"	:	1000,
	"wuxue"	:	1000,
	"pker"	:	1,
	"rich"	:	10000,
	]); 

string query_min_limit()
{
	int i;
	string *mkeys, str="";
	
	mkeys = keys(min_limit);
	for(i=0; i<sizeof(min_limit); i++) 
		str += (mkeys[i]+"\t\t"+min_limit[mkeys[i]]+"\n");
        return str;		
}

int set_min_limit(string top_id, int data)
{
    	if(file_size(query_top_file(top_id))==-1) return 0;
    	min_limit[top_id]=data;
    	return 1;
}

string query_top_file(string top_id)
{
	return TOPTEN_DIR + top_id + ".top";
}

string query_ban_file(string top_id)
{
	return TOPTEN_DIR + top_id + ".ban";
}

int is_banned(string top_id, object ob)
{
   string *banned_id;
   int i;
	
   if( file_size(query_ban_file(top_id)) == -1)
   	return notify_fail("�������а񲻴��ڻ������ݲ�ȫ��\n");
   	
   banned_id = explode(read_file(query_ban_file(top_id)),";");
   for(i=0; i<sizeof(banned_id); i++) {
        if(banned_id[i] == (string)ob->query("id") ) return 1;
   }

   return 0;
}

int do_ban(string top_id, string id, int ban)
{	// allow one player be sorted in one top_id, or not
   string *banned, msg;
   int i;

   if( file_size(query_ban_file(top_id)) == -1 )
   	return notify_fail("�������а񲻴��ڻ������ݲ�ȫ��\n");
   
   msg = read_file( query_ban_file(top_id) );
   banned = explode(msg, ";");
   
   if( ban ){
        for(i=0; i< sizeof(banned); i++)
             	if(banned[i]==id) 
             		return 1;
        return write_file(query_ban_file(top_id),id+";" );
   }

   msg = "";
   for(i=0; i< sizeof(banned); i++){ 
        if(banned[i]==id) continue;
        msg += banned[i];
   }
   write_file(query_ban_file(top_id),msg,1);
   return 1;
}

int add_top(string top_id, string top_name, string top_prop)
{
   string msg, msg_a, msg_b;
   int i;
   
   if(delete_top(top_id)<=0) return -1;  
   
   if(write_file(TOPTEN_FILE, top_id +"(" +top_name+")"+top_prop+"\n")){
   	write_file(query_top_file(top_id),"",1);
   	write_file(query_ban_file(top_id),"",1);
   	return 1;
   }
   
   return 0;   	
}

int delete_top(string top_id)
{
   	string msg, *msg_a, id;
   	int i;   
   
   	rm(query_top_file(top_id));
   	rm(query_ban_file(top_id));
   
   	if(strlen(msg = read_file(TOPTEN_FILE)) > 0 ){   
   		msg_a = explode(msg,"\n");
   		msg="";
   
   		for(i=0; i< sizeof(msg_a); i++){
   			if(strsrch(msg_a[i],top_id+"(") != 0) msg += ( msg_a[i]+"\n");
   		}
   		return write_file(TOPTEN_FILE,msg,1);
   	}
   	
   	return 1;
}

string query_top(string top_id, int op)
{
        string id, name, prop, msg, *msg_a;
        string names, props, ids;
	int i;
	
	names = props = ids = "";
	
	
   	if(strlen(msg = read_file(TOPTEN_FILE)) < 1 )
                return "";
   	
        msg_a = explode(msg,"\n");
        if(sizeof(msg_a) == 0) return "";
        
   	for(i=0; i< sizeof(msg_a); i++){
                if(strlen(msg_a[i]) > 0 && sscanf(msg_a[i],"%s(%s)%s",id,name,prop)==3){
             		switch(op){
             			case TOP_NAME: if(id==top_id) return name;break;
             			case TOP_PROP: if(id==top_id) return prop;break;
             			case TOP_NAME_PROP: return names+";"+ prop;break;
             			case TOP_ID_NAMES: names += ( id+"("+name+")"+";" );break;
             			case TOP_ID_PROPS: props += ( id+"("+prop+")"+";" );break;
             			case TOP_IDS	 :  ids   += ( id+";" );break;
             			default : return "";
        		}
        	}
        }
        if(op == TOP_ID_NAMES) return names;
        if(op == TOP_ID_PROPS) return props;
        if(op == TOP_IDS)      return ids;
        
        return "";	
}

void topten_checkplayer(object player)
{
	int i;
	string *tkeys;
	
        tkeys = explode(query_top("",TOP_IDS),";");
	for(i=0; i< sizeof(tkeys); i++)
		topten_add(player, tkeys[i]);
	return;
}


string topten_query(string type)
{
	string str, sou, *astr, *bstr, name, id;
	int i,j,data;
				
	if(file_size(sou = query_top_file(type)) == -1){		
		return "";
	}
	
	astr=explode(read_file(sou),"\n");
	str =HIG+"�����ݡ���ٴ�"+query_top(type,TOP_NAME)+"���а�\n"NOR;
	for(i=0;i<sizeof(astr);i++)
	{
	
		bstr=explode(astr[i],";");
		str+=HIC"���е�"+chinese_number(i+1)+"��"HIW;
		for(j=0;j<sizeof(bstr);j++)
		{
			if(sscanf(bstr[j],"%s(%s)%d",name,id,data)!=3)
				return "���ݴ���!���ݣ�"+bstr[j]+"\n";
			str+=name+"("+id+")\t";
		}
		str+="\n"NOR;
	}
	return str;
}

int get_all_data(object player,string top_id)
{   
   return (int)player->query(query_top(top_id,TOP_PROP));  
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,name,id,f_name;
	int i,j,k,money;
	
	if(file_size(f_name = query_top_file(type))==-1)
		return notify_fail("û���������а�\n");
	str=read_file(f_name);
	astr=explode(str,"\n");
	for(i=0;i<sizeof(astr);i++)
	{
		if(strsrch(astr[i],pid)!=-1)//���а���id��Ϊ��
		{
			if(strsrch(astr[i],";")==-1)
			//Ϊ���ʾ����ֻ��һ��id����pid
			{
                                     sscanf(astr[i],"%*s(%s)%*d",id);
                                     if ( strcmp(id,pid)!=0 ) continue;
				str="";
				for(j=0;j<sizeof(astr);j++)
					if(j!=i)
						str+=astr[j]+"\n";
				return write_file(f_name,str,1);
			}
			else
			{
				bstr=explode(astr[i],";");
				for(j=0;j<sizeof(bstr);j++)
					if(strsrch(bstr[j],pid)!=-1)//˵�����pid,Ӧ��ȥ��
					{
                                     sscanf(bstr[j],"%*s(%s)%*d",id);
                                     if ( strcmp(id,pid)!=0 ) continue;
						astr[i]="";
						for(k=0;k<sizeof(bstr);k++)
							if(k!=j)
							{
								if((k+1)!=sizeof(bstr)
									&&!((j+1)==sizeof(bstr)&&j==(k+1))
								)
									astr[i]+=bstr[k]+";";
								else
									astr[i]+=bstr[k];
							}
						//����ȥ����j��ѭ��Ӧ��ֹͣ,���ǲ�Ӱ����
					}
				str=implode(astr,"\n");
				return write_file(f_name,str,1);
			}
		}
	}
	return 1;
}

int topten_add(object player,string type)
{
	string str,name,id,str1,b_name,f_name;
	string *astr;
	int i,j,data,t,tmoney;
	object *ob;
	
	if(!objectp(player)||!userp(player))
		return 0;
	
	if(is_banned(type,player)) return 0;
	
			
	if(type=="rich")
	{	ob=all_inventory(player);
		tmoney=0;
		for (t=0;t<sizeof(ob);t++)
			if (stringp(ob[t]->query("money_id")))
				tmoney=tmoney+ob[t]->value();
		player->set("totalmoney",player->query("balance")+tmoney);
	}	
		
	if(get_all_data(player,type) < min_limit[type]) return 0;
	
	if(wizardp(player)) return 0;
	
	if(file_size(f_name=query_top_file(type))==-1)
	{
		str=player->query("name")+"("+player->query("id")+")"+
			get_all_data(player,type);
		return write_file(f_name,str);
	}
	//��Ҫ����
	if(get_all_data(player,type)==-1)
		return notify_fail("���ݲ�ѯ���󣬿����ǲ�ѯ���ʹ���\n");
	//Ӧ�����ų���player��id!
	topten_del(player->query("id"),type);
	str=read_file(f_name);
	astr=explode(str,"\n");
	i=0;
	while(i<sizeof(astr))
	{
		if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3)
			if(sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)
				return notify_fail(b_name+"�ļ����ݴ����������ʦ��\n");
		str="";
		if(data<(int)get_all_data(player,type))
		{
			//�������룬��ʱû���������������У�
			for(j=0;j<sizeof(astr)&&j<99;j++)
			{
				if(j==i)
					str+=player->query("name")+"("+player->query("id")+")"+
						get_all_data(player,type)+"\n";
				str+=astr[j]+"\n";
			}
			return write_file(f_name,str,1);
		}
		else
		if(data==(int)get_all_data(player,type))
		{
			//���ż���
			for(j=0;j<sizeof(astr)&&j<99;j++)
			{
				if(j==i)
					str+=astr[j]+";"+player->query("name")+
						"("+player->query("id")+")"+get_all_data(player,type)+"\n";
				else
					str+=astr[j]+"\n";
			}
			return write_file(f_name,str,1);
		}
		i++;
	}
	if(sizeof(astr)<100)
	{
		str=implode(astr,"\n")+"\n"+player->query("name")+"("+player->query("id")+
			")"+get_all_data(player,type);
		return write_file(f_name,str,1);
	}
	return 0;
}
