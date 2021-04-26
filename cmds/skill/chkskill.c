// chkskill.c
// created by kittt@DJX2000

#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

string *basic_skill = ({ "sword",         
        "blade",       
        "dagger",       
        "unarmed",        
        "stick",        
        "staff",        
        "club" ,      
        "throwing",     
        "force",    
        "parry",       
        "dodge",       
        "magic",      
        "whip",         
        "axe",        
        "finger",      
        "hand",       
        "cuff",       
        "claw",       
        "strike",      
        "leg",         
        "hammer",   });


int main(object me, string arg)
{
	int i, j, w, val;
	string dir,msg;
	mixed *file;
	mapping skl,lrn;

	seteuid(getuid());

	if( !arg ) return notify_fail("ָ���ʽ��chkskill <skill>\n");

	skl = me->query_skills();
	lrn = me->query_learned();
	if (!skl) return notify_fail("��Ŀǰ��û��ѧ���κμ��ܡ�\n");
	if (!skl[arg])  return notify_fail("�㲻�����ּ��ܡ�\n");

	msg = HIG+to_chinese(arg)+" ("+arg+") :\n"NOR;
	msg += "-----------------------------------------------------------\n"CYN;
	msg += "��  ���� "HIY+ skl[arg]+NOR; 
	msg +=CYN"		���������ȣ�"HIY+100*(int)lrn[arg]/(int)((skl[arg]+1) * (skl[arg]+1))+"%\n"NOR;

	val = sizeof(basic_skill);
	while (val--) {
	if (SKILL_D(arg)->valid_enable(basic_skill[val])) {
		w++;
		if(w==1) 	msg +=CYN"\n��  ;��"WHT;
			 else msg +="        ";
		msg += to_chinese(basic_skill[val])+" ("+basic_skill[val]+")\n";
			}
		}
	msg += NOR"-----------------------------------------------------------\n";
	write(msg);

	if(SKILL_D(arg)->type() == "knowledge" && arg != "qianzhu-wandu") {
 		write("��"+to_chinese(arg)+"���������似��û�����⹥���������á�\n");
		return 1; }

	if(member_array(arg, basic_skill)!= -1) {
		write("��"+to_chinese(arg)+"�����ڻ������ܣ�û�����⹥���������á�\n");
		return 1; }

	dir = "/kungfu/skill/"+arg+"/";
	file = get_dir(dir, -1);
	if( !sizeof(file) ) {
		 write("Ŀǰ��"+to_chinese(arg)+"��û���κ����⹥����\n");
		 return 1; }
		
	i = sizeof(file);
	w = 0;

	if(SKILL_D(arg)->valid_enable("force") )	 msg = HIC"�������� (yun/exert) \n\n"HIM;
		else msg = HIC"���⹥�� (perform) \n\n"HIW;
		
	for(j = 0; j<i;j++ ) {
		if(file[j][0][strlen(file[j][0])-2..strlen(file[j][0])] != ".c") continue; 
			file[j][0]= replace_string(file[j][0],".c","");
		msg = sprintf("%s%-15s",msg,file[j][0]);
		w++;   
		if (w == 3 || w == 6 || w == 9 || w == 12 ) msg +="\n";   
	}
	msg += NOR"\n-----------------------------------------------------------\n";
	if (w == 0) msg += "��"HIG+to_chinese(arg)+NOR"�����������С�\n";
		else 
		msg += "��"+HIG+to_chinese(arg)+NOR+"��Ŀǰ����"+chinese_number(w)+"��"+
		 (!SKILL_D(arg)->valid_enable("force")? "���⹥��":"��������")+"��\n"; 
	write(msg+"\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
ָ���ʽ: chkskill [<������>]
 
�г����ֹ������е����⹥����ǰ��������������ܡ� 

������
chkskill huashan-jianfa  

���г����л�ɽ������״̬�����⹥���� 
 
HELP
	);
	return 1;
}
