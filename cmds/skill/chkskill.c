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

	if( !arg ) return notify_fail("指令格式：chkskill <skill>\n");

	skl = me->query_skills();
	lrn = me->query_learned();
	if (!skl) return notify_fail("你目前并没有学会任何技能。\n");
	if (!skl[arg])  return notify_fail("你不会这种技能。\n");

	msg = HIG+to_chinese(arg)+" ("+arg+") :\n"NOR;
	msg += "-----------------------------------------------------------\n"CYN;
	msg += "等  级： "HIY+ skl[arg]+NOR; 
	msg +=CYN"		升级熟练度："HIY+100*(int)lrn[arg]/(int)((skl[arg]+1) * (skl[arg]+1))+"%\n"NOR;

	val = sizeof(basic_skill);
	while (val--) {
	if (SKILL_D(arg)->valid_enable(basic_skill[val])) {
		w++;
		if(w==1) 	msg +=CYN"\n用  途："WHT;
			 else msg +="        ";
		msg += to_chinese(basic_skill[val])+" ("+basic_skill[val]+")\n";
			}
		}
	msg += NOR"-----------------------------------------------------------\n";
	write(msg);

	if(SKILL_D(arg)->type() == "knowledge" && arg != "qianzhu-wandu") {
 		write("「"+to_chinese(arg)+"」不属于武技，没有特殊攻击或者运用。\n");
		return 1; }

	if(member_array(arg, basic_skill)!= -1) {
		write("「"+to_chinese(arg)+"」属于基本技能，没有特殊攻击或者运用。\n");
		return 1; }

	dir = "/kungfu/skill/"+arg+"/";
	file = get_dir(dir, -1);
	if( !sizeof(file) ) {
		 write("目前「"+to_chinese(arg)+"」没有任何特殊攻击。\n");
		 return 1; }
		
	i = sizeof(file);
	w = 0;

	if(SKILL_D(arg)->valid_enable("force") )	 msg = HIC"特殊运用 (yun/exert) \n\n"HIM;
		else msg = HIC"特殊攻击 (perform) \n\n"HIW;
		
	for(j = 0; j<i;j++ ) {
		if(file[j][0][strlen(file[j][0])-2..strlen(file[j][0])] != ".c") continue; 
			file[j][0]= replace_string(file[j][0],".c","");
		msg = sprintf("%s%-15s",msg,file[j][0]);
		w++;   
		if (w == 3 || w == 6 || w == 9 || w == 12 ) msg +="\n";   
	}
	msg += NOR"\n-----------------------------------------------------------\n";
	if (w == 0) msg += "「"HIG+to_chinese(arg)+NOR"」正在整理中。\n";
		else 
		msg += "「"+HIG+to_chinese(arg)+NOR+"」目前共有"+chinese_number(w)+"种"+
		 (!SKILL_D(arg)->valid_enable("force")? "特殊攻击":"特殊运用")+"。\n"; 
	write(msg+"\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式: chkskill [<功夫名>]
 
列出这种功夫所有的特殊攻击，前题是你必须会这项技能。 

范例：
chkskill huashan-jianfa  

会列出所有华山剑法的状态和特殊攻击。 
 
HELP
	);
	return 1;
}
