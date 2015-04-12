clear;close all; clc;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        option = 4;
        
        % 1: affichage de vos donn�es
        % 2: affichage de vos donn�es et d'une droite (� vous d'adapter le
        %           coeff a)
        % 3: affichage d'un polyn�me d'un degr� 2 (idem)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% remarque: les fichiers tailles.m et temps.m (g�n�r�s par tab_to_matlab)
% doivent �tre dans le r�pertoire courant
tailles; % execution du script tailles.m 
temps;   % execution du script temps.m

x = T_tailles;
y = T_temps;
plot(x,y,'.r'); % affichage des temps de calcul
xlabel('taille (n)','FontSize', 30);
ylabel('temps','FontSize', 30);

if (option==1)
    legend('donn�es');
elseif (option==2)
    % affichage d'une droite 
    a = 3; % � adapter
    b = 0; % th�oriquement � adapter mais on peut laisser 0 par approximation
    y_droite = a*x+b;
    hold on;
    plot(x,y_droite,'b'); % affichage du polyn�me
    hold off;
    legend('donn�es','test de regression manuelle');
elseif (option==3)
    % affichage d'un polyn�me de degr� 2
    a = 7; % � adapter
    b=-30;   % th�oriquement � adapter mais on peut laisser 0 par approximation
    c=10;   % th�oriquement � adapter mais on peut laisser 0 par approximation
    y_quadratique = a*x.^2+b*x+c;
    hold on;
    plot(x,y_quadratique,'b'); % affichage du polyn�me
    hold off;
    legend('donn�es','test de regression manuelle');
elseif (option==4)
    fac=0.0005;
    exponentielle = factorial(x)*fac;
    hold on;
    plot(x, exponentielle, 'b');
    hold off;
    legend('donnees', 'exponentielle');
end