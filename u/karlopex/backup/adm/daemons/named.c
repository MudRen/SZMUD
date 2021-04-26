// /adm/daemons/named.c
// ����������
// create by akuma@mudnow
// 2000/9/26
// ver 1.0

#include <ansi.h>

string *name_xing=({
		"��","Ǯ","��","��","��","��","֣","��","��","¬","����","��","��","����",
		"��","��","ţ","��","��","��","��","��","³","��","��","��","��","��","��",
		"ʷ","��","��","��","��","��","��","��","��","��","��","��","κ","��","��",
		"ŷ��","��","��","��","��","��","Ѧ","��","��","��","��","��","ͯ","��",
		"��","��","��","֣","��","��","��","��","��","ʯ","ʱ","��","��","��","��",
		"��","ξ��","��","��","��","��","��","��","ë","��","��","ʩ","��","��",
		"��","��","��","��","��","��","��","��","��","�Ϲ�","˾��","��","��","��",
		"��","��","��","���","����","����","�Ϲ�","��","��","Σ","��","��","��","��"
		});
string *pinyin_xing=({
		"zhao","qian","sun","li","zhou","wu","zheng","wang","song","lu","gongsun","guan","lin","huyan",
		"yang","ma","niu","lv","qin","hua","chai","zhu","lu","wu","zhang","dong","xu","suo","dai",
		"shi","liu","mu","lei","ruan","yan","xie","huang","shan","han","hao","peng","wei","qi","xiao",
		"ouyang","deng","ling","an","guo","jiang","xue","gao","bao","kong","jin","xiang","tong","meng",
		"hou","chen","liang","zheng","gong","tao","fan","bao","fan","shi","shi","duan","zuo","xin","yu",
		"yu","yuchi","cao","ji","cui","jia","gu","du","mao","he","fei","shi","pan","yan",
		"yu","fang","yan","tang","lian","shan","huo","feng","feng","shangguan","sima","zuo","fu","wen",
		"jing","xing","lin","linghu","dugu","wenren","nangong","shen","fan","wei","yang","kong","yue","zou"
		});

string *name_ming1=({
		"С",
		"��","��","��","��","��","��","��","��","��","ʮ",
		"��",
		"��",
		"��",
		"��",
		"��","��","ˮ","ľ","��",
		"��","��","��","��","��","��",
		"��","��","��","��","��","˳","��","��","��","��","��",
		"Ϊ",
		"ʤ","��","ƽ","��","��","��","Ⱥ","��",
		"��","��","��","��","��","��","��","��","��","��","��","��","��","��",
		"Ӣ","��","Ǳ","ط","��","��","��","��","��","��","��","��","��","־",
		"̴","��","��","��","��","´","��","��","��","��","��","��","��","�",
		"��","��","��","��","��","��","��","��","��","��","��","��","ѩ",
		"��","˾","��","��","��","ӯ","Ľ","��","��","��","��",
		"��",
		});
string *pinyin_ming1=({
		"xiao",
		"da","er","san","si","wu","liu","qi","ba","jiu","shi",
		"a",
		"tuan",
		"sheng",
		"bai",
		"tie","jin","shui","mu","huo",
		"chang","jiu","you","wu","duo","shao",
		"ming","gui","hu","bao","qing","shun","yun","fei","jian","xiang","chao",
		"wei",
		"sheng","heng","ping","hong","tian","bao","qun","tian",
		"peng","long","kun","guan","yu","ke","sheng","liang","lang","tao","bo","luan","jie","jian",
		"ying","xing","qian","yin","yun","ri","meng","wei","ling","yun","feng","bo","zhi","zhi",
		"tan","qiong","mian","jing","zai","lu","ge","kuai","xuan","zheng","xuan","dong","biao","qiu",
		"jing","jie","yong","hai","jing","hang","xiao","cheng","sheng","hui","xiang","hong","xue",
		"zhong","si","ding","zhong","bai","ying","mu","yu","yun","tian","li",
		"fei",
		});


string *name_ming2=({
		"��","��","��","��","��","��","��","��",
		"��","ݷ","��","˼","Ľ","��","��","��","��","��","��","��","��","��","��",
		"��",
		"��",
		"��",
		"��","ţ","��",
		"��",
		"��","��","��","��","��","��","��","��","��","��","��","��","��","��",
		"��","��","��","��","��","��","��","��","��","�","��","��","ѩ",
		"��","��","��",
		"��","��","��",
		"��","��","��","��",
		"��","��","��","˳","��","��","��","��",
		"��",
		"��","ӱ",
		"��","��",
		"÷",
		});
string *pinyin_ming2=({
		"er","san","si","wu","liu","qi","ba","jiu",
		"lin","shen","shen","si","mu","yong","yong","hu","hen","hun","ning","yi","yi","yi","yi",
		"lang",
		"er",
		"wan",
		"hu","niu","bao",
		"zi",
		"peng","long","kun","guan","yu","ke","sheng","liang","lang","tao","bo","luan","jie","jian",
		"jing","jie","yong","hai","jing","hang","xiao","cheng","sheng","hui","xiang","hong","xue",
		"fu","gui","fu",
		"nian","yue","ri",
		"sheng","tian","min","ming",
		"qing","long","kang","shun","cai","feng","yu","yun",
		"kang",
		"hua","ying",
		"chong","chong",
		"mei",
		});

string *nick_first=({
		HIB"�Ϻ�"NOR,HIY"ƽԭ"NOR,HIW"�ɶ�"NOR,HIG"����"NOR,RED"ƽ��"NOR,WHT"����"NOR,BLU"����"NOR,HIW"Ʈѩ"NOR,YEL"���"NOR,GRN"����"NOR,MAG"���"NOR,RED"Ϧ��"NOR,
	GRN"����"NOR,});

string *nick_second=({MAG"��"NOR,CYN"��"NOR,RED"��"NOR,WHT"ǹ"NOR,BLU"��"NOR,YEL"��"NOR,HIR"��"NOR,CYN"��"NOR,HIB"��"NOR,HIY"��"NOR,HIR"����"NOR,HIG"��"NOR,WHT"��"NOR,BLU"��"NOR,});

string create_name()
{
	string name,pinyin_name;
	int xing,ming1,ming2,yes1;
	xing=random(sizeof(name_xing));
	ming1=random(sizeof(name_ming1));
	ming2=random(sizeof(name_ming2));
	yes1=random(3);
	
	name = name_xing[xing];
	name+= yes1?name_ming1[ming1]:"";
	name+= name_ming2[ming2];
	
	pinyin_name = pinyin_xing[xing];
	pinyin_name+= " ";
	pinyin_name+= yes1?pinyin_ming1[ming1]:"";
	pinyin_name+= pinyin_ming2[ming2];
	
	return(sprintf("%s@%s",name,pinyin_name));
}

string create_nick()
{
	string nick1,nick2;
	nick1=nick_first[random(sizeof(nick_first))];
	nick2=nick_second[random(sizeof(nick_second))];
	if(random(5)>3)
		return nick1+"һ"+nick2;
	else
		return nick1+nick2;
}
