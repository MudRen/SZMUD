//xuanpiao.c
//create by rama@sz

inherit ITEM;

#include <ansi.h>
#include <mudlib.h>

void get_id( string arg);
int check_legal_id(string id);
int check_id(string id, int x);
void confirm_xuan(string yn);
void get_menpai(string arg);
int check_menpai(string arg);
string *opt1 = ({ 
"25��������",
"30��������",
"35��������",
"40��������",
"45��������",
"55��������",
"65��������",
"99��������",
"�������",
"���µ�һ����",
});
int *age = ({ 
14,25,30,35,40,45,55,65,99,200,
});
mapping menpai = ([
	"hs":"��ɽ��",
	"xx":"������",
	"wd":"�䵱��",
	"dl":"����μ�",
	"gb":"ؤ��",
	"xs":"ѩɽ��",
	"th":"�һ���",
	"gm":"��Ĺ��",
	"sl":"������",
	"qz":"ȫ���",
	"em":"������",
	"bt":"����ɽ",
	"kl":"������",
/*	"mj":"����",
	"xy":"��ң��",
	"ry":"�������",
	"ts":"��ɽ��",
	"lj":"���չ�",
	"mr":"����Ľ��",*/
]);
string mpl = "hs �� ��ɽ��    xx �� ������    wd �� �䵱��    kl �� ������\nxs �� ѩɽ��    th �� �һ���    gm �� ��Ĺ��    sl �� ������\nqz �� ȫ���    em �� ������    bt �� ����ɽ    gb �� ؤ��\ndl �� ����μ�\n";

string *msg=({"","","","","","","","","","",""});
string temp="";
string mpname, name, wujue = "";
int i=0, cnt=0;

void create()
{
        set_name("������ѡƱ", ({ "xuan piao","piao" }));
        set_weight(10);
        set("long","����һ�ű�����ѡƱ��
����д�ţ�
        25�������飺
        30�������飺
        35�������飺
        40�������飺
        45�������飺
        55�������飺
        65�������飺
        99�������飺
        �������(��������,���мȿ�)��
        ���µ�һ���ɣ�
�������xuan����дѡƱ��\n");
        set("unit", "��");
        set("value", 0);
        setup();
              
}

void init()
{
        add_action("do_xuan","xuan");
}

int do_xuan()
{
        object ob = this_object();
        if( ob->query("done",1))
                return notify_fail("ѡƱ���ܸ��ġ�\n");
        if( i>=10)
        {
		if ( !ob->query_temp("quit") ){
	                write(HIR"��ѡƱֻ�ܹ�ѡ��һ�Σ�һ��ȷ�Ͼ��޷����ģ�\n"NOR);
	                write("��ѡ����ô�����ѡ���˾����롰Y�����ߡ�y����(Yes/No)");
	                }
                input_to( (:confirm_xuan :) );
                return 1;
        }
	if (i == 0){
		write(HIW"��д��ע�����\n"NOR);
		write(HIY"������ѡƱÿ��ֻ��һ�ݡ�\n");
		write("������ѡƱֻ�ܹ�ѡ��һ�Σ�һ��ȷ�Ͼ��޷����ģ�\n");
		write("�������в���ѡ����Ŀ�á�no��������\n");
		write("�������в�����ѡ���á�tuichu���˳�ѡ��\n\n\n"NOR);
	}
	if (i == 9){
		write("���ڡ�" + INTERMUD_MUD_CNAME + "���е����������¿�ѡ��\n"+HIG+mpl+HIC+"ѡ���ʱ��д��дƴ�����������������ԡ�\n"NOR);
       		write("�����"+opt1[i]+"���ĸ����ɣ�");
	        input_to( (: get_menpai :));
		return 1;
	}else if (i == 8)
       		write("�����"+opt1[i]+"(��������,���мȿ�)������λ���֣�");
	else write("�����"+opt1[i]+"˭��Ӯ��");
        input_to( (: get_id :));
        return 1;
        
}

void get_id( string arg)
{
	int a, b;
        if(arg != "no" && arg != "tuichu")
	{
	        arg = lower_case(arg);
		if (i == 8 && arg[0..0] != ",")
		{
			b = sizeof(explode(arg, "\," ));
			if (b != 5)
			{ 
        			write(ESC + "[1A" + ESC + "[256D"+"��д��������������ˣ�����дһ����ѡ�������");				
		                input_to("get_id");
		                return;
			}
			for(a=0;a<b;a++)
			{
		  	        if(!check_id(explode(arg, "\," )[a], i))
				{
			                input_to("get_id");
			                return;
				}
				msg[i] += name;	
			}
			msg[i] = msg[i][0..<3];
			this_object()->set(opt1[i],explode(msg[i], "\��" ));
			write(wujue);
		}else if(!check_legal_id(arg) 
	          || !check_id(arg, i))
	        {
	                input_to("get_id");
	                return;
	        }else{
		        msg[i]=name;	        
			this_object()->set(opt1[i],msg[i][0..<3]);
		}
	}else{
		if (arg == "no"){
			write(ESC + "[1A" + ESC + "[256D" + HIG +opt1[i]+"��������δѡ��\n"NOR);
			msg[i]="����δѡ��";
		}else if ( arg == "tuichu" ){
	                write(HIR"��ѡ�����˳���"NOR);
                	write("��������˾����롰Y�����ߡ�y����(Yes/No)");
			this_object()->set_temp("quit",1);
			i = 10;
        		do_xuan();
			return;
		}
	}
	temp += opt1[i]+"�� "+msg[i]+"\n"; 
        i++;
        do_xuan();
}       
void get_menpai( string arg)
{

        if(!arg || arg == "")
        {
		write("�㻹û��д���������ѡ��д��no���ɡ�");
                input_to("get_menpai");
                return;
        }else if(arg != "no"){
 		if(!check_menpai(arg))
	        {
	                input_to("get_menpai");
	                return;
	        }
		msg[i] = mpname;
	}else{
		write(ESC + "[1A" + ESC + "[256D" + HIG +opt1[i]+"��������δѡ��\n"NOR);
		msg[i]="����δѡ��";
	}
	this_object()->set(opt1[i],msg[i]);
        temp += opt1[i]+"�� "+msg[i]+"\n"; 
        i++;
        do_xuan();
}       
int check_menpai(string mp)
{
	string *mpx;
	write(ESC + "[1A" + ESC + "[256D" + "���ڼ���������д�������ݵ���Ч�ԣ�\n");
	mpx = keys(menpai);
	for (int j=0; j<sizeof(mpx); j++) {
		if (mp == mpx[j] || mp == menpai[mpx[j]])
		{
			if (mp == mpx[j]) mpname = menpai[mpx[j]];
			write(ESC + "[1A" + ESC + "[256D"+HIG"������д��"+mpname+"�ǡ�" + INTERMUD_MUD_CNAME + "���е����ɣ�����������\n"NOR);
			return 1;
		}
	}
	write(ESC + "[1A" + ESC + "[256D"+HIR + mp + "������Ч����������룡������ѡ"+opt1[i]+"��\n"NOR);
	return 0;
}

int check_legal_id(string id)
{
    int len;
    len = strlen(id);
    
     if( (strlen(id) < 3) || (strlen(id) > 60 )  ) {
        write("\n����ID��ʽ���������"HIY"����ַ�"NOR"��"HIR","NOR"����������");
        return 0;
    }
    return 1;
}
int check_id(string id, int x)
{
        object ob;
        string *mpx, mpl;
	if (x == 8 && cnt == 0) write(ESC + "[1A" + ESC + "[256D" + "���ڼ�������ѡ�����ID����Ч�ԣ�\n");
	else if (x != 8) write(ESC + "[1A" + ESC + "[256D" + "���ڼ���"+ id + "����Ч�ԣ�\n");
	if (!objectp(ob = find_player(id)))
	{
		ob = new(USER_OB);
	        ob->set("id", id);   
		if( !ob->restore() ) {
			if (x == 8)
	        		write(ESC + "[1A" + ESC + "[256D"+HIR+ "������"+ id + "δע�ᣡ"NOR"������ѡ�����");
	        	else write(ESC + "[1A" + ESC + "[256D"+HIR+ id + "��δע�ᣡ"NOR"������ѡ"+opt1[i]+"˭��Ӯ��");
			destruct(ob);
	                return 0;
		}
	}
	name = ob->name()+"("+id+")��";
	if (x == 8){
		cnt++;
		if (cnt == 5)
			write(ESC + "[1A" + ESC + "[256D"+HIG"�������ID������ϣ�ȫ��������������ѡ���"+opt1[i]+"�ǣ�\n"NOR);
		wujue += ob->short(1) + "\n";
		if (!objectp(ob)) destruct(ob);
		return 1;
	}
	if (ob->query("age") > age[x] && ob->query("age") <= age[x+1] ){
		write(ESC + "[1A" + ESC + "[256D"+HIG"���ݽ�����ϣ�" + NOR + ob->short(1) + HIG + "����"+opt1[i]+"��������\n"NOR);
		if (!objectp(ob)) destruct(ob);
		return 1;
	}else{
		write(ESC + "[1A" + ESC + "[256D" + HIR + name + "������������������ѡ��"+opt1[i]+"˭��Ӯ��"NOR);
		if (!objectp(ob)) destruct(ob);
		return 0;
	}
}
	
void confirm_xuan(string yn)
{
        object ob=this_object();
        int n;
        if( yn[0]!='y' && yn[0]!='Y' ) 
        {
                write("�Ǻúÿ���һ�°ɡ�\n");
		temp = "";
                i=0;
                cnt=0;
                wujue = "";
                return;
        }
	if ( ob->query_temp("quit") ){
		write("�����ٿ���һ�°ɡ�\n");
		temp = "";
                i=0;
                cnt=0;
                wujue = "";
 		return;
	}
	temp += "\n����ѡƱ������"+ctime(time())[0..15]+"��д�ġ�\n";
        ob->set("done_time",time());
        ob->set("long",temp);
        ob->set("done",1);
        ob->set_name(this_player()->query("name")+"�ı���ѡƱ",({this_player()->query("id")+"'s piao", "piao"}) );
        write("������������ѡƱ��\n");
        return;         
}
