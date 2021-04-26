// chaxun command..
// Rewritten by lisser@sz
// All Copyrights.

#include <ansi.h>
#include <dbase.h>
#include <mudlib.h>

inherit F_SAVE;
inherit F_CLEAN_UP;
#include "/clone/misc/diaocha.h"

object data=load_object("/clone/misc/form");
int help(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int    i, j, x;
        object ob;
        string from, to;
        string *choice, item, *data3, *id, str = "";
	mapping data1, data2, todata;
	data1 = data->query_sheet();
	if (!arg){
		help(me);
		return 1;
	}
	if ( arg == "-c" ){
		write("Ŀǰ���У�"+chinese_number(sizeof(data1))+"λ"+MUD_NAME+"��Ҳμ��˵��顣\n");
		return 1;
	}else if ( arg == "-l" ){
		write("Ŀǰ���У�"+chinese_number(sizeof(data1))+"λ"+MUD_NAME+"��Ҳμ��˵��飬�������£�\n");
		id = keys(data1);
		for (i=0;i<sizeof(id);i++)
		{
			if (!objectp(ob = find_player(id[i])))
			{
				ob = new(USER_OB);
			        ob->set("id", id[i]);   
				if( !ob->restore() ) {
					str = sprintf("%s%-18s%s", str, "������"+"("+id[i]+")", (x%7==6? " \n":""));
					destruct(ob);
				}else{
					str = sprintf("%s%-18s%s", str, ob->query("name")+"("+id[i]+")", (x%7==6? " \n":""));
					destruct(ob);
				}
			}else str = sprintf("%s%-18s%s", str, ob->query("name")+"("+id[i]+")", (x%7==6? " \n":""));
		}			
		write(str + "\n");
		return 1;
	}else if (sscanf(arg, "%s %s", from, to) == 2){
	        data2 = data1[from];
	        if (! data2 || ! sizeof(data2))
	                return notify_fail("û��(" + from + ")������ID��\n");
	
	        if ((todata = data1[to]) && sizeof(todata))
	                return notify_fail("���ID(" + to + ")�Ѿ����ڣ����ܸ��ǡ�\n");
	
	        todata = allocate_mapping(sizeof(data2));
	        data3 = keys(data2);
	        for (i = 0; i < sizeof(data3); i++)
	                todata[data3[i]] = data2[data3[i]];
		if (!objectp(ob = find_player(to)))
		{
			ob = new(USER_OB);
		        ob->set("id", to);   
			if( !ob->restore() ) {
				sprintf("���޴��ˣ�");
				destruct(ob);
				return 1;
			}
			data->save_sheet(ob, todata);
			destruct(ob);
		}else data->save_sheet(ob, todata);
        	printf("(%s)���Ƴ���(%s)�Ĵ𰸡�\n", from, to);
		return 1;
	}else{
		data2 = data1[arg];
		if (!mapp(data2)) return notify_fail("Ŀǰ"+arg+"û�вμ����������\n");
	                
		for (int step = 0; step < sizeof( form );step++)
		{
			string answer="";
		        item   = k_form[step];
		        choice = form[item];
			data3 = data2[step];
		        j = sizeof(choice);
		        
		        write( HIG + ( step + 1 ) + "��" + item + "\n\n" + NOR );
		        for ( i = 0; i < j; i ++ )
		        {
				write( index[i] + " " + choice[i] +"\n" ); 
			}
		        for ( x = 0; x < sizeof(data3); x ++ )
		        {
				if (explode(data3[x], "\:" )[0] != "self_opinion")
					answer += data3[x]+"��";
				else answer += "�Լ����������������¡�\n"+explode(data3[x], "\:" )[1]+"��";
			}
			write( "\n"+arg+"ѡ����ǣ�"HIG+answer[0..<3]+NOR"��\n" );
			
		}
	}
	return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : chaxun [���ID | -c | -l ]
���У�
	ID ��ѯ��ҵĻش������
	-c ��ѯ�μӵ������������
	-l ��ѯ�μӵ������ҡ�
HELP);
    return 1;
}

