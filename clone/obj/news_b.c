// Code of ShenZhou
//wzfeng@xkx 2000 7
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
void input_news_name(string news_name,object me);
void start_edit(string content);
int add_news_data(mapping news_p);

mapping *news_xkx=({ });
mapping news;
void create()
{
	
	//news_xkx=*new(class news_data);
 	seteuid(getuid());
}
string query_save_file()
{
        return DATA_DIR + "board/news";
}
void news_clean()
{
	news_xkx=({ });

	return ;
}
//Get news list

void query_list_full(object player)
{
	int i,j,k;
	string news_list,msg,time;
	msg="";

	restore();
	if(!pointerp(news_xkx))
		return 0;
	msg+=sprintf("%s",HIY"�����ݡ����������б�\n"NOR
		"��������������������������������������������������������������������������\n");
	j=sizeof(news_xkx);
	for(k=0;k<sizeof(news_xkx);k++)
	{
		i=j-1-k;
		time=ctime(news_xkx[i]["time"]);
		msg+=sprintf("[%2d]%-=36s %18s %s\n",i+1,""+news_xkx[i]["title"]+"",news_xkx[i]["who_post"],time[20..23]+" "+time[4..6]+" "+time[8..9]);
	}
	player->start_more(msg);
}

string query_list()
{
	int num,i,k;
	int last_read_time;
	string msg;
	msg="";
	restore();
	if( !pointerp(news_xkx) || !sizeof(news_xkx) )
		return ("Ŀǰû���κ����š�\n");

	last_read_time = this_player()->query("news_last_read");	

	if(!this_player()->query("news_last_read") )
			num = 1;
		else
			for(num = 1; num<=sizeof(news_xkx); num++)
				if(news_xkx[num-1]["time"] > last_read_time) break;


	msg+=sprintf("%s",HIW"�����ݡ����������б�(����"+chinese_number(sizeof(news_xkx)-num+1)+"��δ��)\n"NOR
		"������������������������������������������������������������������������������\n");

	//msg+="\t\t\t\t������"+chinese_number(sizeof(news_xkx)-num+1)+"������δ��\n";
	for(i=num-1; i<sizeof(news_xkx); i++) {
		//k=sizeof(news_xkx)-1-i;
		k=i;
		msg += sprintf("%s[%2d]" NOR,
			news_xkx[k]["time"] > last_read_time ? HIY: "",
			k+1);
		msg += (sprintf("     %-=36s %18s (%s)\n",
			news_xkx[k]["title"], news_xkx[k]["who_post"],
			ctime(news_xkx[k]["time"])[0..15] ))[4..<0];
	}
	
	return msg;
}

//printf("[%d] %36s %18s (%s)\n"
void input_news_name(string news_name,object me)
{
	
	news=([]);
	news["title"]=news_name;
	news["who_post"]=me->query("name")+"("+me->query("id")+")";
	news["time"]=time();
	tell_object(me,"��༭��Ҫ�������ŵ�����:\n");
	me->edit( (: start_edit:) );
}
void start_edit(string content)
{
	news["content"]=content;
	add_news_data(news);
	save();
	destruct(this_object());
}
int add_news_data(mapping news_p)
{
	restore();
	
	if( !pointerp(news_xkx) )
        {
         news_xkx = ({ news_p });
        }
        else news_xkx += ({ news_p });
		return 1;
}

string do_read(string arg)
{
	int num;
	int last_read_time;
	string msg;
	restore();
	last_read_time = this_player()->query("news_last_read");
	
	if( !pointerp(news_xkx) || !sizeof(news_xkx) )
		return ("Ŀǰû���κ����š�\n");
	
		if( arg=="new" || arg=="next" ) 
		{
		if(!this_player()->query("news_last_read") )
			num = 1;
		else
			for(num = 1; num<=sizeof(news_xkx); num++)
				if(news_xkx[num-1]["time"] > last_read_time) break;
		}
		else if( !sscanf(arg, "%d", num) )
		return ("��Ҫ���ڼ������ţ�\n");

	if( num < 1 || num > sizeof(news_xkx) )
		return ("û���������š�\n");
	num--;

		msg= ( sprintf("[%d] %-=36s %18s (%s)\n"
	"-------------------------------------------------------------------------------\n",
		num + 1, news_xkx[num]["title"], news_xkx[num]["who_post"],
		ctime(news_xkx[num]["time"])[0..15])
		+ news_xkx[num]["content"] );
		//write(msg);
		if(!this_player()->query("news_last_read") )
		this_player()->set("news_last_read",  news_xkx[num]["time"] );
	else 
		if(news_xkx[num]["time"] > this_player()->query("news_last_read") )
			this_player()->set("news_last_read",news_xkx[num]["time"]) ;
		return msg;
}

string do_discard(string arg)
{
	int num;
	restore();
	if( !arg || sscanf(arg, "%d", num)!=1 )
		return ("ָ���ʽ��newsdel <���ű��>\n");
	if( !arrayp(news_xkx) || num < 1 || num > sizeof(news_xkx) )
		return ("û���������š�\n");
	num--;
	if( news_xkx[num]["who_post"] != (string) this_player()->query("name") + "("+this_player()->query("id")+")"
	&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
	&& (string)SECURITY_D->get_status(this_player(1)) != "(arch)")

		return ("�������Ų�����д�ġ�\n");
	news_xkx = news_xkx[0..num-1] + news_xkx[num+1..<1];
	save();
	return ("ɾ���� " + (num+1) + "������....Ok��\n");

}
